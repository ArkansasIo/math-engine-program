#!/usr/bin/env python3
"""Small repository structure validator."""
import json
from pathlib import Path
root = Path(__file__).resolve().parents[1]
required = ["CMakeLists.txt", "README.md", "LICENSE", "include/axiomforge/core/graph.hpp", "src/core/graph.cpp", "apps/cli/main.cpp", "tests/test_main.cpp", "config/product.json"]
missing = [name for name in required if not (root / name).is_file()]
try:
    json.loads((root / "config/product.json").read_text(encoding="utf-8"))
except Exception as exc:
    missing.append(f"config/product.json (invalid JSON: {exc})")
if missing:
    raise SystemExit("Validation failed: " + ", ".join(missing))
print(f"Validation passed: {len(required)} required paths checked.")
