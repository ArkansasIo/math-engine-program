export type Mode="Math"|"Team"|"Debug"|"Build"|"Review";
export interface User {id:string;email:string}
export interface Project {id:string;name:string;description:string;role:string;created_at:string}
export interface Branch {id:string;name:string;head_revision_id:string|null}
export interface Revision {id:string;message:string;author_id:string;parent_revision_id:string|null;document:Record<string,unknown>;created_at:string}
export interface Job {id:string;kind:string;status:string;output?:unknown;error?:string;created_at:string}
