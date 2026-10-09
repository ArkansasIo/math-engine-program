#!/usr/bin/env python3
"""Validate PROJECT_MANIFEST.json shape and path uniqueness."""
import json
import re
from pathlib import Path
root=Path(__file__).resolve().parents[1]
data=json.loads((root/"PROJECT_MANIFEST.json").read_text(encoding="utf-8"))
files=data.get("files")
if not isinstance(files,list): raise SystemExit("Manifest files must be a list")
paths=[x.get("path") for x in files if isinstance(x,dict)]
if len(paths)!=len(files): raise SystemExit("Every manifest entry must be an object with a path")
if len(paths)!=len(set(paths)): raise SystemExit("Manifest contains duplicate paths")
for item in files:
    if not re.fullmatch(r"[0-9a-f]{40}",str(item.get("git_blob_sha",""))): raise SystemExit(f"Invalid Git blob SHA for {item.get('path')}")
    if not isinstance(item.get("size_bytes"),int) or item["size_bytes"]<0: raise SystemExit(f"Invalid size for {item.get('path')}")
if data.get("file_count")!=len(files): raise SystemExit("Manifest file_count does not match entries")
print(f"Manifest schema passed: {len(files)} files.")
