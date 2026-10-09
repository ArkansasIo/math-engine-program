interface Props {title:string;description:string;icon?:string;}
export default function EmptyState({title,description,icon="∑"}:Props){return <section className="empty"><div className="empty-icon">{icon}</div><h2>{title}</h2><p>{description}</p></section>}
