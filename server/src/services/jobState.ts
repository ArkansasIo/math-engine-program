export type JobState="queued"|"running"|"succeeded"|"failed"|"cancelled";
const transitions:Record<JobState,readonly JobState[]>={queued:["running","cancelled"],running:["succeeded","failed","cancelled"],succeeded:[],failed:["queued"],cancelled:[]};
export function canTransitionJobState(from:JobState,to:JobState):boolean{return transitions[from].includes(to);}
export function assertJobTransition(from:JobState,to:JobState):void{if(!canTransitionJobState(from,to))throw new Error(`Invalid job state transition: ${from} -> ${to}`);}
