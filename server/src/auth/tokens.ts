import jwt from "jsonwebtoken";
import { config } from "../config";
export type Role="owner"|"editor"|"reviewer"|"viewer";
export interface Principal { sub:string; email:string; }
export function issueAccessToken(user:Principal):string{return jwt.sign({email:user.email},config.JWT_SECRET,{subject:user.sub,issuer:config.JWT_ISSUER,audience:"axiomforge-api",expiresIn:"15m"});}
export function verifyAccessToken(token:string):Principal{const p=jwt.verify(token,config.JWT_SECRET,{issuer:config.JWT_ISSUER,audience:"axiomforge-api"});if(typeof p==="string"||typeof p.sub!=="string"||typeof p.email!=="string")throw new Error("Invalid token claims");return{sub:p.sub,email:p.email};}
