import {Request,Response,NextFunction} from "express";
const buckets=new Map<string,{count:number;reset:number}>();
export function loginRateLimit(req:Request,res:Response,next:NextFunction){const key=req.ip||"unknown",now=Date.now(),b=buckets.get(key);if(!b||b.reset<=now){buckets.set(key,{count:1,reset:now+60_000});next();return;}if(b.count>=10){res.status(429).json({error:"rate_limited"});return;}b.count++;next();}
