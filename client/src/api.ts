import type {Branch,Job,Project,Revision,User} from "./types";
const base=import.meta.env.VITE_API_BASE_URL??"http://localhost:8080/api/v1";
let token:string|null=null;
export function setToken(value:string|null){token=value}
async function request<T>(path:string,init:RequestInit={}):Promise<T>{const headers=new Headers(init.headers);headers.set("Content-Type","application/json");if(token)headers.set("Authorization",`Bearer ${token}`);const response=await fetch(base+path,{...init,headers});if(!response.ok){const data=await response.json().catch(()=>({}));throw new Error(data.error??`Request failed (${response.status})`);}if(response.status===204)return undefined as T;return response.json() as Promise<T>}
export async function login(email:string,password:string){const r=await request<{accessToken:string;user:User}>("/auth/login",{method:"POST",body:JSON.stringify({email,password})});setToken(r.accessToken);return r;}
export async function register(email:string,password:string){const r=await request<{accessToken:string;user:User}>("/auth/register",{method:"POST",body:JSON.stringify({email,password})});setToken(r.accessToken);return r;}
export async function projects(){return (await request<{projects:Project[]}>("/projects")).projects}
export async function createProject(name:string,description:string){return request<{project:Project;defaultBranch:Branch}>("/projects",{method:"POST",body:JSON.stringify({name,description})})}
export async function branches(projectId:string){return (await request<{branches:Branch[]}>(`/revisions/${projectId}/branches`)).branches}
export async function commitRevision(projectId:string,branchId:string,message:string,document:Record<string,unknown>,expectedHeadId:string|null){return request<{revision:Revision}>(`/revisions/${projectId}/branches/${branchId}/revisions`,{method:"POST",body:JSON.stringify({message,document,expectedHeadId})})}
export async function submitJob(projectId:string,operation:string,a:number,b?:number){return request<{job:Job}>("/jobs",{method:"POST",body:JSON.stringify({projectId,kind:"math.evaluate",input:{operation,a,...(b===undefined?{}:{b})}})})}
export async function getJob(id:string){return request<{job:Job}>(`/jobs/${id}`)}
export function eventSocket(projectId:string,onEvent:(event:unknown)=>void){if(!token)return()=>{};const url=new URL(base.replace(/^http/,"ws")+"/ws");url.searchParams.set("token",token);const ws=new WebSocket(url);ws.onopen=()=>ws.send(JSON.stringify({type:"subscribe",projectId}));ws.onmessage=e=>{try{onEvent(JSON.parse(e.data))}catch{}};return()=>ws.close();}
export async function createBranch(projectId:string,name:string){return request<{branch:Branch}>(`/revisions/${projectId}/branches`,{method:"POST",body:JSON.stringify({name})})}
export async function revisionHistory(projectId:string,branchId:string){return (await request<{revisions:Revision[]}>(`/revisions/${projectId}/branches/${branchId}/revisions`)).revisions}

import type {Member,Release,Review} from "./types";
export async function members(projectId:string){return (await request<{members:Member[]}>(`/projects/${projectId}/members`)).members}
export async function addMember(projectId:string,email:string,role:"editor"|"reviewer"|"viewer"){return request<{membership:unknown}>(`/projects/${projectId}/members`,{method:"POST",body:JSON.stringify({email,role})})}
export async function reviews(projectId:string){return (await request<{reviews:Review[]}>(`/revisions/${projectId}/reviews`)).reviews}
export async function createReview(projectId:string,branchId:string,title:string,body:string){return request<{review:Review}>(`/revisions/${projectId}/reviews`,{method:"POST",body:JSON.stringify({branchId,title,body})})}
export async function updateReview(projectId:string,reviewId:string,status:"approved"|"changes_requested"|"closed"){return request<{review:Pick<Review,"id"|"status">}>(`/revisions/${projectId}/reviews/${reviewId}`,{method:"PATCH",body:JSON.stringify({status})})}
export async function releases(projectId:string){return (await request<{releases:Release[]}>(`/revisions/${projectId}/releases`)).releases}
export async function createRelease(projectId:string,revisionId:string,version:string,channel:"development"|"beta"|"stable"){return request<{release:Release}>(`/revisions/${projectId}/releases`,{method:"POST",body:JSON.stringify({revisionId,version,channel})})}
export async function publishRelease(projectId:string,releaseId:string){return request<{release:Release}>(`/revisions/${projectId}/releases/${releaseId}/publish`,{method:"POST"})}
