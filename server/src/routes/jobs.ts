import {Router} from "express";
import {z} from "zod";
import {pool} from "../db/pool";
import {requireAuth} from "../middleware/auth";
import {requireProjectRole} from "../services/permissions";
export const jobsRouter=Router();jobsRouter.use(requireAuth);
const schema=z.object({projectId:z.string().uuid(),kind:z.enum(["math.evaluate","build","test","file.validate"]),input:z.record(z.unknown())});
jobsRouter.post("/",async(req,res,next)=>{try{const v=schema.parse(req.body);if(!(await requireProjectRole(v.projectId,req.principal!.sub,"editor"))){res.status(403).json({error:"forbidden"});return;}const r=await pool.query("INSERT INTO jobs(project_id,submitted_by,kind,input) VALUES($1,$2,$3,$4) RETURNING id,project_id,kind,status,created_at",[v.projectId,req.principal!.sub,v.kind,JSON.stringify(v.input)]);res.status(202).json({job:r.rows[0]});}catch(e){next(e);}});
jobsRouter.get("/:jobId",async(req,res,next)=>{try{const r=await pool.query("SELECT j.id,j.project_id,j.kind,j.status,j.output,j.error,j.created_at,j.started_at,j.finished_at FROM jobs j JOIN project_members m ON m.project_id=j.project_id WHERE j.id=$1 AND m.user_id=$2",[req.params.jobId,req.principal!.sub]);if(!r.rows[0]){res.status(404).json({error:"job_not_found"});return;}res.json({job:r.rows[0]});}catch(e){next(e);}});
