import type {Revision} from "../types";
interface Props {revisions:Revision[];limit?:number;}
export default function RevisionHistory({revisions,limit=10}:Props){if(!revisions.length)return <p className="muted">No revisions committed to this branch yet.</p>;return <div className="revision-history">{revisions.slice(0,limit).map(r=><div className="history-item" key={r.id}><b>{r.message}</b><small>{new Date(r.created_at).toLocaleString()}</small><code>{r.id.slice(0,12)}</code></div>)}</div>}
