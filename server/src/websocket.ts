import {Server as HttpServer} from "node:http";
import {WebSocketServer,WebSocket} from "ws";
import {verifyAccessToken} from "./auth/tokens";
import {eventHub} from "./services/events";
import {requireProjectRole} from "./services/permissions";
type Client={socket:WebSocket;userId:string;projects:Set<string>};
export function attachWebSockets(server:HttpServer){const wss=new WebSocketServer({noServer:true});const clients=new Set<Client>();const unsubscribe=eventHub.subscribe(event=>{for(const c of clients){if(c.projects.has(event.projectId)&&c.socket.readyState===WebSocket.OPEN)c.socket.send(JSON.stringify(event));}});
 server.on("upgrade",(req,socket,head)=>{const url=new URL(req.url??"/","http://localhost");if(url.pathname!=="/api/v1/ws"){socket.destroy();return;}const token=url.searchParams.get("token");if(!token){socket.write("HTTP/1.1 401 Unauthorized\r\n\r\n");socket.destroy();return;}try{verifyAccessToken(token);}catch{socket.write("HTTP/1.1 401 Unauthorized\r\n\r\n");socket.destroy();return;}wss.handleUpgrade(req,socket,head,ws=>wss.emit("connection",ws,req));});
 wss.on("connection",(socket,req)=>{const url=new URL(req.url??"/","http://localhost");let principal;try{principal=verifyAccessToken(url.searchParams.get("token")!);}catch{socket.close(1008,"unauthorized");return;}const c:Client={socket,userId:principal.sub,projects:new Set()};clients.add(c);socket.on("message",async raw=>{try{const msg=JSON.parse(raw.toString()) as {type?:string;projectId?:string};if(msg.type==="subscribe"&&typeof msg.projectId==="string"&&await requireProjectRole(msg.projectId,c.userId,"viewer")){c.projects.add(msg.projectId);socket.send(JSON.stringify({type:"subscribed",projectId:msg.projectId}));}}catch{socket.send(JSON.stringify({type:"error",error:"invalid_message"}));}});socket.on("close",()=>clients.delete(c));});
 wss.on("close",unsubscribe);return wss;}
