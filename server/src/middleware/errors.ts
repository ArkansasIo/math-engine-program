import {NextFunction,Request,Response} from "express";
import {ZodError} from "zod";
export function notFound(_req:Request,res:Response){res.status(404).json({error:"not_found"});}
export function errorHandler(err:unknown,_req:Request,res:Response,_next:NextFunction){
 if(res.headersSent)return;
 if(err instanceof ZodError){res.status(400).json({error:"validation_error",issues:err.issues.map(i=>({path:i.path,message:i.message}))});return;}
 if(err instanceof SyntaxError && "status" in err && (err as {status?:number}).status===400){res.status(400).json({error:"invalid_json"});return;}
 console.error(err);res.status(500).json({error:"internal_server_error"});
}
