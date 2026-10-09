import test from "node:test";
import assert from "node:assert/strict";
import {evaluateMath} from "./services/mathEvaluator";
test("math worker: addition",()=>assert.deepEqual(evaluateMath({operation:"add",a:12,b:30}),{operation:"add",value:42}));
test("math worker: prime",()=>assert.deepEqual(evaluateMath({operation:"prime",a:97}),{value:97,prime:true}));
test("math worker: composite",()=>assert.deepEqual(evaluateMath({operation:"prime",a:99}),{value:99,prime:false}));
test("math worker: division by zero rejected",()=>assert.throws(()=>evaluateMath({operation:"divide",a:1,b:0}),/division by zero/));
test("math worker: unreasonable prime workload rejected",()=>assert.throws(()=>evaluateMath({operation:"prime",a:1_000_000_000_001}),/worker limit/));
test("math worker: non-finite result rejected",()=>assert.throws(()=>evaluateMath({operation:"multiply",a:Number.MAX_VALUE,b:2}),/not finite/));
