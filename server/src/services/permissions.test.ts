import test from "node:test";
import assert from "node:assert/strict";
const rank={viewer:1,reviewer:2,editor:3,owner:4} as const;
function allows(actual:keyof typeof rank,minimum:keyof typeof rank){return rank[actual]>=rank[minimum];}
test("owner can edit and review",()=>{assert.equal(allows("owner","editor"),true);assert.equal(allows("owner","reviewer"),true);});
test("viewer cannot edit",()=>assert.equal(allows("viewer","editor"),false));
test("reviewer cannot edit",()=>assert.equal(allows("reviewer","editor"),false));
