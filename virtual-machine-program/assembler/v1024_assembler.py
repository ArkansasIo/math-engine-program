#!/usr/bin/env python3
import json, pathlib, sys
OPS=json.loads((pathlib.Path(__file__).parent.parent/"isa"/"opcodes.json").read_text())
for line in sys.stdin:
    s=line.strip()
    if not s or s.startswith(";"): continue
    op=s.split()[0].upper()
    if op not in OPS: raise SystemExit(f"unknown opcode: {op}")
    print(f"{OPS[op]:04X} {s}")
