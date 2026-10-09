import { NextFunction,Request,Response } from "express";
import { verifyAccessToken } from "../auth/tokens";
declare global { namespace Express { interface Request { principal?:{sub:string;email:string} } } }
export function requireAuth(req:Request,res:Response,next:NextFunction){const h=req.header("authorization");if(!h?.startsWith("Bearer ")){res.status(401).json({error:"authentication_required"});return;}try{req.principal=verifyAccessToken(h.slice(7));next();}catch{res.status(401).json({error:"invalid_token"});}}
