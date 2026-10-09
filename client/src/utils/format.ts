export function formatDate(value:string){const date=new Date(value);return Number.isNaN(date.getTime())?"Unknown date":date.toLocaleString();}
export function shortId(value:string,length=12){return value.slice(0,Math.max(4,Math.min(32,length)));}
export function formatRole(role:string){return role.replaceAll("_"," ").replace(/^./,c=>c.toUpperCase());}
