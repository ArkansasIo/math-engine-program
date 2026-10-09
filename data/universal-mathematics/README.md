# Universal Mathematics Data Registry

This folder adds a reproducible registry layer to AxiomForge without replacing existing engine code.

## Contents
- `term-registry.json` / `term-registry.yaml`: five mathematical term families and signed-integer domain rules.
- `term-schema.sql`: SQLite-compatible schema for term families, materialized records, dataset specifications, and finite materialized windows.
- `term-generator.py`: deterministic CSV/JSONL generator for any requested finite interval of integers.
- `difficulty-scale.json` / `difficulty-scale.yaml`: the 1–1500 scale, eight tier bands, and six dimensions.
- `dimension-registry.schema.json`: JSON Schema for dimension entries.
- `problem-record.schema.json`: JSON Schema for problem records and proof/verification states.
- `dataset-manifest.json`: inventory, counts, domain policy, and reproducibility rules.

## Unbounded domains
The integers are unbounded in both directions. A finite file cannot list every integer, rational, real, or complex value. This registry stores definitions and generator rules and materializes only finite requested windows.

## Generate a signed integer range
```bash
python3 data/universal-mathematics/term-generator.py --start -1000 --end 1000 --format csv --output integers.csv
python3 data/universal-mathematics/term-generator.py --start -1000 --end 1000 --format jsonl --output integers.jsonl
```

IDs are deterministic: `TERM-Z--3`, `TERM-Z-+0`, and `TERM-Z-+3`.

## Verification policy
Numerical or external symbolic output is computational evidence, not automatically a proof. The registry distinguishes computed results, numerically verified results, formally proved statements, conjectures, counterexamples, open problems, and unknown status.
