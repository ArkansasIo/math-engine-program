import "dotenv/config";
import {runWorker} from "./jobWorker";
import {pool} from "../db/pool";
const controller=new AbortController();
process.on("SIGINT",()=>controller.abort());process.on("SIGTERM",()=>controller.abort());
runWorker(controller.signal).catch(error=>{console.error(error);process.exitCode=1;}).finally(()=>pool.end());
