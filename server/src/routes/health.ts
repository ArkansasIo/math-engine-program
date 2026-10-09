import {Router} from "express";
import {pingDatabase} from "../db/pool";
export const healthRouter=Router();
healthRouter.get("/live",(_req,res)=>res.json({status:"ok"}));
healthRouter.get("/ready",async(_req,res)=>{try{await pingDatabase();res.json({status:"ready",database:"ok"});}catch{res.status(503).json({status:"not_ready",database:"unavailable"});}});
