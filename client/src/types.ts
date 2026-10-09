export type Mode="Math"|"Team"|"Debug"|"Build"|"Review";
export interface User {id:string;email:string}
export interface Project {id:string;name:string;description:string;role:string;created_at:string}
export interface Branch {id:string;name:string;head_revision_id:string|null}
export interface Revision {id:string;message:string;author_id:string;parent_revision_id:string|null;document:Record<string,unknown>;created_at:string}
export interface Job {id:string;kind:string;status:string;output?:unknown;error?:string;created_at:string}
export interface Member {id:string;email:string;role:"owner"|"editor"|"reviewer"|"viewer";created_at:string}
export interface Review {id:string;branch_id:string;author_id:string;status:"open"|"approved"|"changes_requested"|"closed";title:string;body:string;created_at:string}
export interface Release {id:string;revision_id:string;version:string;channel:"development"|"beta"|"stable";status:"draft"|"published"|"withdrawn";created_at:string}
