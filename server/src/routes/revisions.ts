import {Router} from "express";
import {z} from "zod";
import {pool} from "../db/pool";
import {requireAuth} from "../middleware/auth";
import {requireProjectRole} from "../services/permissions";
import {eventHub} from "../services/events";

export const revisionsRouter=Router();
revisionsRouter.use(requireAuth);
const commitSchema=z.object({
 parentRevisionId:z.string().uuid().nullable().optional(),
 message:z.string().trim().min(1).max(500),
 document:z.record(z.unknown()),
 expectedHeadId:z.string().uuid().nullable().optional()
});
const branchSchema=z.object({name:z.string().trim().min(1).max(80).regex(/^[a-zA-Z0-9][a-zA-Z0-9._/-]*$/)});

revisionsRouter.get("/:projectId/branches",async(req,res,next)=>{
 try{
  if(!(await requireProjectRole(req.params.projectId,req.principal!.sub,"viewer"))){res.status(403).json({error:"forbidden"});return;}
  const r=await pool.query("SELECT id,name,head_revision_id,created_at FROM branches WHERE project_id=$1 ORDER BY name",[req.params.projectId]);
  res.json({branches:r.rows});
 }catch(e){next(e);}
});

revisionsRouter.post("/:projectId/branches",async(req,res,next)=>{
 try{
  const projectId=req.params.projectId;
  if(!(await requireProjectRole(projectId,req.principal!.sub,"editor"))){res.status(403).json({error:"forbidden"});return;}
  const v=branchSchema.parse(req.body);
  const r=await pool.query("INSERT INTO branches(project_id,name,created_by) VALUES($1,$2,$3) RETURNING id,project_id,name,head_revision_id,created_at",[projectId,v.name,req.principal!.sub]);
  res.status(201).json({branch:r.rows[0]});
 }catch(e){if((e as {code?:string}).code==="23505"){res.status(409).json({error:"branch_name_exists"});return;}next(e);}
});

revisionsRouter.get("/:projectId/branches/:branchId/revisions",async(req,res,next)=>{
 try{
  const {projectId,branchId}=req.params;
  if(!(await requireProjectRole(projectId,req.principal!.sub,"viewer"))){res.status(403).json({error:"forbidden"});return;}
  const branch=await pool.query("SELECT id FROM branches WHERE id=$1 AND project_id=$2",[branchId,projectId]);
  if(!branch.rows[0]){res.status(404).json({error:"branch_not_found"});return;}
  const requested=Number.parseInt(String(req.query.limit??"50"),10);
  const limit=Number.isFinite(requested)?Math.max(1,Math.min(100,requested)):50;
  const r=await pool.query("SELECT id,parent_revision_id,author_id,message,document,created_at FROM revisions WHERE project_id=$1 AND branch_id=$2 ORDER BY created_at DESC LIMIT $3",[projectId,branchId,limit]);
  res.json({revisions:r.rows});
 }catch(e){next(e);}
});

revisionsRouter.post("/:projectId/branches/:branchId/revisions",async(req,res,next)=>{
 const client=await pool.connect();
 try{
  const projectId=req.params.projectId,branchId=req.params.branchId;
  if(!(await requireProjectRole(projectId,req.principal!.sub,"editor"))){res.status(403).json({error:"forbidden"});return;}
  const v=commitSchema.parse(req.body);
  await client.query("BEGIN");
  const br=await client.query("SELECT id,head_revision_id FROM branches WHERE id=$1 AND project_id=$2 FOR UPDATE",[branchId,projectId]);
  if(!br.rows[0]){await client.query("ROLLBACK");res.status(404).json({error:"branch_not_found"});return;}
  const head=br.rows[0].head_revision_id as string|null;
  if(v.expectedHeadId!==undefined&&v.expectedHeadId!==head){await client.query("ROLLBACK");res.status(409).json({error:"revision_conflict",currentHeadId:head});return;}
  const parent=v.parentRevisionId===undefined?head:v.parentRevisionId;
  if(parent!==null){const exists=await client.query("SELECT 1 FROM revisions WHERE id=$1 AND branch_id=$2",[parent,branchId]);if(!exists.rowCount){await client.query("ROLLBACK");res.status(422).json({error:"invalid_parent_revision"});return;}}
  const r=await client.query("INSERT INTO revisions(project_id,branch_id,parent_revision_id,author_id,message,document) VALUES($1,$2,$3,$4,$5,$6) RETURNING id,project_id,branch_id,parent_revision_id,author_id,message,document,created_at",[projectId,branchId,parent,req.principal!.sub,v.message,JSON.stringify(v.document)]);
  const revision=r.rows[0];
  await client.query("UPDATE branches SET head_revision_id=$1 WHERE id=$2",[revision.id,branchId]);
  const eventResult=await client.query("INSERT INTO collaboration_events(project_id,actor_id,event_type,payload) VALUES($1,$2,'revision.created',$3) RETURNING id",[projectId,req.principal!.sub,JSON.stringify({branchId,revisionId:revision.id,parentRevisionId:parent})]);
  await client.query("COMMIT");
  eventHub.publish({type:"revision.created",projectId,actorId:req.principal!.sub,payload:{branchId,revisionId:revision.id,parentRevisionId:parent},createdAt:new Date().toISOString(),eventId:String(eventResult.rows[0].id)});
  res.status(201).json({revision});
 }catch(e){await client.query("ROLLBACK");next(e);}finally{client.release();}
});
