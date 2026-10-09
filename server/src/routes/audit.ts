import {Router} from "express";
import {requireAuth} from "../middleware/auth";
import {requireProjectRole} from "../services/permissions";
import {readProjectAudit} from "../services/audit";
export const auditRouter=Router();auditRouter.use(requireAuth);
auditRouter.get("/:projectId",async(req,res,next)=>{try{if(!(await requireProjectRole(req.params.projectId,req.principal!.sub,"owner"))){res.status(403).json({error:"owner_required"});return;}const raw=Number.parseInt(String(req.query.limit??"100"),10),limit=Number.isFinite(raw)?Math.max(1,Math.min(100,raw)):100;res.json({entries:await readProjectAudit(req.params.projectId,limit)});}catch(e){next(e);}});
