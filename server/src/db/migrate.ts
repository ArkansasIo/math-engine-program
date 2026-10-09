import fs from "node:fs/promises";
import path from "node:path";
import {pool} from "./pool";
async function main(){
 const dir=path.resolve(process.cwd(),"migrations");
 const files=(await fs.readdir(dir)).filter(f=>/^\d+_[a-z0-9_-]+\.sql$/i.test(f)).sort();
 await pool.query("CREATE TABLE IF NOT EXISTS schema_migrations(name text PRIMARY KEY,applied_at timestamptz NOT NULL DEFAULT now())");
 for(const file of files){
  const exists=await pool.query("SELECT 1 FROM schema_migrations WHERE name=$1",[file]);
  if(exists.rowCount)continue;
  const sql=await fs.readFile(path.join(dir,file),"utf8");
  const client=await pool.connect();
  try{await client.query("BEGIN");await client.query(sql);await client.query("INSERT INTO schema_migrations(name) VALUES($1)",[file]);await client.query("COMMIT");console.log("Applied migration",file);}
  catch(error){await client.query("ROLLBACK");throw error;}
  finally{client.release();}
 }
}
main().catch(error=>{console.error("Migration failed",error);process.exitCode=1;}).finally(()=>pool.end());
