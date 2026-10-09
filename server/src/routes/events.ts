import {Router} from "express";
import {pool} from "../db/pool";
import {requireAuth} from "../middleware/auth";
import {requireProjectRole} from "../services/permissions";
export const eventsRouter=Router();eventsRouter.use(requireAuth);
eventsRouter.get("/:projectId",async(req,res,next)=>{try{const projectId=req.params.projectId;if(!(await requireProjectRole(projectId,req.principal!.sub,"viewer"))){res.status(403).json({error:"forbidden"});return;}const raw=String(req.query.afterId??"0");if(!/^\d+$/.test(raw)){res.status(400).json({error:"invalid_after_id"});return;}const after=BigInt(raw);if(after>BigInt(Number.MAX_SAFE_INTEGER)){res.status(400).json({error:"after_id_too_large"});return;}const n=Number.parseInt(String(req.query.limit??"100"),10),limit=Number.isFinite(n)?Math.max(1,Math.min(100,n)):100;const r=await pool.query("SELECT id,event_type,actor_id,payload,created_at FROM collaboration_events WHERE project_id=$1 AND id>$2 ORDER BY id ASC LIMIT $3",[projectId,after.toString(),limit]);res.json({events:r.rows.map(row=>({...row,id:String(row.id)}))});}catch(e){next(e);}});
