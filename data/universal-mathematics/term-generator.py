#!/usr/bin/env python3
"""Generate deterministic finite windows from the unbounded integer domain."""
import argparse
import csv
import json
from pathlib import Path

def integer_records(start: int, end: int):
    if start > end:
        raise ValueError("start must be <= end")
    for n in range(start, end + 1):
        yield {
            "id": f"TERM-Z-{n:+d}",
            "family_id": "TERM-FAM-001",
            "canonical_value": str(n),
            "integer_value": n,
            "sign_class": "negative" if n < 0 else ("positive" if n > 0 else "zero"),
            "absolute_value": abs(n),
            "parity": "even" if n % 2 == 0 else "odd",
        }

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--start", type=int, required=True)
    parser.add_argument("--end", type=int, required=True)
    parser.add_argument("--format", choices=("csv", "jsonl"), default="csv")
    parser.add_argument("--output", default="integer_window.csv")
    args = parser.parse_args()
    if args.start > args.end:
        parser.error("--start must be <= --end")
    path = Path(args.output)
    records = integer_records(args.start, args.end)
    if args.format == "jsonl":
        with path.open("w", encoding="utf-8", newline="\n") as stream:
            count = 0
            for record in records:
                stream.write(json.dumps(record, ensure_ascii=False) + "\n")
                count += 1
    else:
        fields = ["id", "family_id", "canonical_value", "integer_value",
                  "sign_class", "absolute_value", "parity"]
        with path.open("w", encoding="utf-8", newline="") as stream:
            writer = csv.DictWriter(stream, fieldnames=fields)
            writer.writeheader()
            count = 0
            for record in records:
                writer.writerow(record)
                count += 1
    print(f"Wrote {count} records to {path}")

if __name__ == "__main__":
    main()
