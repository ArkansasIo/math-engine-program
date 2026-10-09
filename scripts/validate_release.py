#!/usr/bin/env python3
"""Validate product/build identity consistency before creating a release."""
import json
import re
from pathlib import Path
root=Path(__file__).resolve().parents[1]
product=json.loads((root/"config/product.json").read_text(encoding="utf-8"))
build=json.loads((root/"build/build-info.json").read_text(encoding="utf-8"))
errors=[]
for key in ("application_name","product_id","version","build_number","build_id"):
    a=str(product.get(key,""));b=str(build.get(key,""))
    if not a or a!=b: errors.append(f"{key} differs or is missing: product={a!r}, build={b!r}")
if not re.fullmatch(r"\d+\.\d+\.\d+(?:-[A-Za-z0-9.-]+)?",str(product.get("version",""))): errors.append("version is not semantic-version shaped")
if errors: raise SystemExit("Release metadata validation failed:\n- "+"\n- ".join(errors))
print("Release metadata validation passed.")
