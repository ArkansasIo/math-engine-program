import test from "node:test";
import assert from "node:assert/strict";
import {canTransitionJobState,assertJobTransition} from "./jobState";
test("queued job can start or cancel",()=>{assert.equal(canTransitionJobState("queued","running"),true);assert.equal(canTransitionJobState("queued","cancelled"),true);});
test("running job can finish",()=>{assert.equal(canTransitionJobState("running","succeeded"),true);assert.equal(canTransitionJobState("running","failed"),true);});
test("completed jobs cannot restart",()=>{assert.equal(canTransitionJobState("succeeded","running"),false);assert.throws(()=>assertJobTransition("cancelled","running"),/Invalid job state transition/);});
