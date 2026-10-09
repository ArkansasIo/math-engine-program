import { NextFunction,Request,Response } from "express";
export function notFound(_req:Request,res:Response){res.status(404).json({error:"not_found"});}
export function errorHandler(err:unknown,_req:Request,res:Response,_next:NextFunction){console.error(err);if(res.headersSent)return;res.status(500).json({error:"internal_server_error"});}
