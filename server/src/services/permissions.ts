import {pool} from "../db/pool";
export type ProjectRole="owner"|"editor"|"reviewer"|"viewer";
const rank:Record<ProjectRole,number>={viewer:1,reviewer:2,editor:3,owner:4};
export async function projectRole(projectId:string,userId:string):Promise<ProjectRole|null>{const r=await pool.query<{role:ProjectRole}>("SELECT role FROM project_members WHERE project_id=$1 AND user_id=$2",[projectId,userId]);return r.rows[0]?.role??null;}
export async function requireProjectRole(projectId:string,userId:string,minimum:ProjectRole):Promise<boolean>{const role=await projectRole(projectId,userId);return role!==null&&rank[role]>=rank[minimum];}
