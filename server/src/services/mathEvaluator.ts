export type MathOperation="add"|"subtract"|"multiply"|"divide"|"prime";
export interface MathInput {operation?:unknown;a?:unknown;b?:unknown;}
export function evaluateMath(input:MathInput):Record<string,unknown>{
 const op=input.operation,a=input.a,b=input.b;
 if(typeof a!=="number"||!Number.isFinite(a))throw new Error("input.a must be a finite number");
 if(op==="prime"){
  if(!Number.isSafeInteger(a))throw new Error("prime input must be a safe integer");
  if(Math.abs(a)>1_000_000_000_000)throw new Error("prime input exceeds the development worker limit");
  if(a<2)return{value:a,prime:false};
  for(let d=2;d<=Math.sqrt(a);d++)if(a%d===0)return{value:a,prime:false};
  return{value:a,prime:true};
 }
 if(typeof b!=="number"||!Number.isFinite(b))throw new Error("input.b must be a finite number");
 let value:number;
 if(op==="add")value=a+b;
 else if(op==="subtract")value=a-b;
 else if(op==="multiply")value=a*b;
 else if(op==="divide"){if(b===0)throw new Error("division by zero");value=a/b;}
 else throw new Error("unsupported operation");
 if(!Number.isFinite(value))throw new Error("result is not finite");
 return{operation:op,value};
}
