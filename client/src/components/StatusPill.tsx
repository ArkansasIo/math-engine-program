interface Props {status:string;label?:string;}
export default function StatusPill({status,label}:Props){return <span className={"job-status "+status}>{label??status.replaceAll("_"," ")}</span>}
