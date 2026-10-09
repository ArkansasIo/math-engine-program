import type {Mode} from "../types";
interface Props {modes:Mode[];active:Mode;onChange:(mode:Mode)=>void;}
export default function ModeBar({modes,active,onChange}:Props){return <nav className="modebar" aria-label="Workspace mode">{modes.map(mode=><button key={mode} className={active===mode?"mode active":"mode"} aria-current={active===mode?"page":undefined} onClick={()=>onChange(mode)}>{mode}</button>)}</nav>}
