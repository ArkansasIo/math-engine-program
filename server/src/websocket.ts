import {Server as HttpServer} from "node:http";
import {WebSocketServer,WebSocket} from "ws";
import {verifyAccessToken} from "./auth/tokens";
import {pool} from "./db/pool";
import {eventHub,PlatformEvent} from "./services/events";
import {requireProjectRole} from "./services/permissions";
type Client={socket:WebSocket;userId:string;projects:Set<string>;lastSeen:Map<string,number>;replaying:Set<string>;pending:Map<string,PlatformEvent[]>};
export function attachWebSockets(server:HttpServer){
 const wss=new WebSocketServer({noServer:true});
 const clients=new Set<Client>();
 const unsubscribe=eventHub.subscribe((event:PlatformEvent)=>{
  for(const c of clients){
   if(!c.projects.has(event.projectId)||c.socket.readyState!==WebSocket.OPEN)continue;
   if(c.replaying.has(event.projectId)){const pending=c.pending.get(event.projectId)??[];pending.push(event);c.pending.set(event.projectId,pending);continue;}
   const id=Number(event.eventId??0),seen=c.lastSeen.get(event.projectId)??0;
   if(id&&id<=seen)continue;
   c.socket.send(JSON.stringify(event));
   if(id)c.lastSeen.set(event.projectId,id);
  }
 });
 server.on("upgrade",(req,socket,head)=>{
  const url=new URL(req.url??"/","http://localhost");
  if(url.pathname!=="/api/v1/ws"){socket.destroy();return;}
  const token=url.searchParams.get("token");
  if(!token){socket.write("HTTP/1.1 401 Unauthorized\r\n\r\n");socket.destroy();return;}
  try{verifyAccessToken(token);}catch{socket.write("HTTP/1.1 401 Unauthorized\r\n\r\n");socket.destroy();return;}
  wss.handleUpgrade(req,socket,head,ws=>wss.emit("connection",ws,req));
 });
 wss.on("connection",(socket,req)=>{
  const url=new URL(req.url??"/","http://localhost");
  let principal;
  try{principal=verifyAccessToken(url.searchParams.get("token")!);}catch{socket.close(1008,"unauthorized");return;}
  const c:Client={socket,userId:principal.sub,projects:new Set(),lastSeen:new Map(),replaying:new Set(),pending:new Map()};
  clients.add(c);
  socket.on("message",async raw=>{
   try{
    const msg=JSON.parse(raw.toString()) as {type?:string;projectId?:string;afterId?:number};
    if(msg.type==="subscribe"&&typeof msg.projectId==="string"&&await requireProjectRole(msg.projectId,c.userId,"viewer")){
     const projectId=msg.projectId,after=Number.isSafeInteger(msg.afterId)&&Number(msg.afterId)>0?Number(msg.afterId):0;
     c.projects.add(projectId);c.lastSeen.set(projectId,after);c.replaying.add(projectId);
     const backlog=await pool.query("SELECT id,event_type,actor_id,payload,created_at FROM collaboration_events WHERE project_id=$1 AND id>$2 ORDER BY id ASC LIMIT 100",[projectId,after]);
     for(const row of backlog.rows){
      const id=Number(row.id),seen=c.lastSeen.get(projectId)??0;if(id<=seen)continue;
      if(socket.readyState!==WebSocket.OPEN)break;
      socket.send(JSON.stringify({type:row.event_type,projectId,actorId:row.actor_id,payload:row.payload,createdAt:row.created_at,eventId:String(row.id)}));
      c.lastSeen.set(projectId,id);
     }
     c.replaying.delete(projectId);
     const pending=(c.pending.get(projectId)??[]).sort((a,b)=>Number(a.eventId??0)-Number(b.eventId??0));c.pending.delete(projectId);
     for(const event of pending){const id=Number(event.eventId??0),seen=c.lastSeen.get(projectId)??0;if(id&&id<=seen)continue;if(socket.readyState!==WebSocket.OPEN)break;socket.send(JSON.stringify(event));if(id)c.lastSeen.set(projectId,id);}
     socket.send(JSON.stringify({type:"subscribed",projectId,lastEventId:c.lastSeen.get(projectId)??after}));
    }
   }catch{
    for(const projectId of [...c.replaying]){
     c.replaying.delete(projectId);
     const pending=(c.pending.get(projectId)??[]).sort((a,b)=>Number(a.eventId??0)-Number(b.eventId??0));c.pending.delete(projectId);
     for(const event of pending){if(socket.readyState!==WebSocket.OPEN)break;const id=Number(event.eventId??0),seen=c.lastSeen.get(projectId)??0;if(id&&id<=seen)continue;socket.send(JSON.stringify(event));if(id)c.lastSeen.set(projectId,id);}
    }
    socket.send(JSON.stringify({type:"error",error:"sync_failed"}));
   }
  });
  socket.on("close",()=>clients.delete(c));
 });
 wss.on("close",unsubscribe);
 return wss;
}
