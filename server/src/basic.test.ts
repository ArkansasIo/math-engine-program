import test from "node:test";
import assert from "node:assert/strict";
function evaluate(input:{operation:string;a:number;b?:number}){if(!Number.isFinite(input.a))throw new Error("invalid input");if(input.operation==="prime"){if(!Number.isSafeInteger(input.a))throw new Error("invalid integer");if(input.a<2)return false;for(let d=2;d<=Math.sqrt(input.a);d++)if(input.a%d===0)return false;return true;}if(typeof input.b!=="number"||!Number.isFinite(input.b))throw new Error("invalid second input");if(input.operation==="add")return input.a+input.b;if(input.operation==="divide"){if(input.b===0)throw new Error("division by zero");return input.a/input.b;}throw new Error("unsupported operation");}
test("safe math worker: addition",()=>assert.equal(evaluate({operation:"add",a:12,b:30}),42));
test("safe math worker: prime",()=>assert.equal(evaluate({operation:"prime",a:97}),true));
test("safe math worker: composite",()=>assert.equal(evaluate({operation:"prime",a:99}),false));
test("safe math worker: division by zero rejected",()=>assert.throws(()=>evaluate({operation:"divide",a:1,b:0}),/division by zero/));
