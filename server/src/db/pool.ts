import { Pool } from "pg";
import { config } from "../config";
export const pool=new Pool({connectionString:config.DATABASE_URL,max:15,idleTimeoutMillis:30_000,connectionTimeoutMillis:5_000,ssl:config.NODE_ENV==="production"?{rejectUnauthorized:true}:undefined});
pool.on("error",(error)=>console.error("Unexpected idle PostgreSQL client error",error));
export async function pingDatabase():Promise<void>{await pool.query("SELECT 1");}
