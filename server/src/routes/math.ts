import {Router} from "express";
import {z} from "zod";
import {requireAuth} from "../middleware/auth";
import {evaluateMath} from "../services/mathEvaluator";
export const mathRouter=Router();mathRouter.use(requireAuth);
const inputSchema=z.object({operation:z.enum(["add","subtract","multiply","divide","prime"]),a:z.number().finite(),b:z.number().finite().optional()});
mathRouter.post("/evaluate",async(req,res)=>{const parsed=inputSchema.safeParse(req.body);if(!parsed.success){res.status(400).json({error:"validation_error",issues:parsed.error.issues});return;}try{res.json({result:evaluateMath(parsed.data)});}catch(e){res.status(422).json({error:"math_evaluation_failed",message:e instanceof Error?e.message:"invalid math input"});}});
