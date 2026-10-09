import "dotenv/config";
import { z } from "zod";
const schema = z.object({
 NODE_ENV:z.enum(["development","test","production"]).default("development"),
 PORT:z.coerce.number().int().min(1).max(65535).default(8080),
 DATABASE_URL:z.string().min(1),
 JWT_SECRET:z.string().min(32,"JWT_SECRET must be at least 32 characters"),
 JWT_ISSUER:z.string().default("axiomforge"),
 CORS_ORIGIN:z.string().default("http://localhost:3000"),
 TLS_KEY_PATH:z.string().optional().default(""),
 TLS_CERT_PATH:z.string().optional().default(""),
 LOG_LEVEL:z.enum(["debug","info","warn","error"]).default("info")
});
export const config=schema.parse(process.env);
if ((config.TLS_KEY_PATH==="") !== (config.TLS_CERT_PATH==="")) throw new Error("TLS_KEY_PATH and TLS_CERT_PATH must be configured together");
if(config.NODE_ENV==="production" && config.JWT_SECRET==="replace-with-at-least-32-random-bytes") throw new Error("A production JWT secret must be configured");
