import {EventEmitter} from "node:events";
export type PlatformEvent={type:string;projectId:string;actorId:string;payload:Record<string,unknown>;createdAt:string;eventId?:string};
class EventHub extends EventEmitter { publish(event:PlatformEvent){this.emit("event",event);} subscribe(listener:(event:PlatformEvent)=>void){this.on("event",listener);return()=>this.off("event",listener);} }
export const eventHub=new EventHub();
