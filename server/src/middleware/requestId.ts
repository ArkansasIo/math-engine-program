import {randomUUID} from "node:crypto";
import {NextFunction,Request,Response} from "express";
declare global { namespace Express { interface Request { requestId?:string } } }
export function requestId(req:Request,res:Response,next:NextFunction){const supplied=req.header("x-request-id");const id=supplied&&/^[A-Za-z0-9._:-]{1,100}$/.test(supplied)?supplied:randomUUID();req.requestId=id;res.setHeader("X-Request-Id",id);next();}
