#!/usr/bin/env python3
"""Tests for the Universal Mathematics finite integer-window generator.

Run with:
    python3 -m unittest discover -s data/universal-mathematics/tests -v
"""
import csv
import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GENERATOR_PATH = ROOT / "term-generator.py"
SPEC = importlib.util.spec_from_file_location("term_generator", GENERATOR_PATH)
generator = importlib.util.module_from_spec(SPEC)
assert SPEC and SPEC.loader
SPEC.loader.exec_module(generator)


class IntegerRecordsTests(unittest.TestCase):
    def test_inclusive_range_and_record_shape(self):
        records = list(generator.integer_records(-1, 1))
        self.assertEqual([r["integer_value"] for r in records], [-1, 0, 1])
        self.assertEqual(
            set(records[0]),
            {
                "id", "family_id", "canonical_value", "integer_value",
                "sign_class", "absolute_value", "parity",
            },
        )

    def test_sign_absolute_value_and_parity(self):
        records = list(generator.integer_records(-4, 4))
        by_value = {record["integer_value"]: record for record in records}
        self.assertEqual(by_value[-4]["sign_class"], "negative")
        self.assertEqual(by_value[-4]["absolute_value"], 4)
        self.assertEqual(by_value[-4]["parity"], "even")
        self.assertEqual(by_value[0]["sign_class"], "zero")
        self.assertEqual(by_value[0]["absolute_value"], 0)
        self.assertEqual(by_value[0]["parity"], "even")
        self.assertEqual(by_value[3]["sign_class"], "positive")
        self.assertEqual(by_value[3]["parity"], "odd")

    def test_ids_and_records_are_deterministic(self):
        self.assertEqual(
            list(generator.integer_records(-2, 2)),
            list(generator.integer_records(-2, 2)),
        )
        self.assertEqual(
            [r["id"] for r in generator.integer_records(-1, 1)],
            ["TERM-Z--1", "TERM-Z-+0", "TERM-Z-+1"],
        )

    def test_reversed_range_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "start must be <= end"):
            list(generator.integer_records(2, 1))

    def test_single_value_range(self):
        self.assertEqual(
            [r["integer_value"] for r in generator.integer_records(7, 7)],
            [7],
        )


class GeneratorCliTests(unittest.TestCase):
    def run_cli(self, output_format):
        with tempfile.TemporaryDirectory() as temporary:
            output = Path(temporary) / ("integers.jsonl" if output_format == "jsonl" else "integers.csv")
            import subprocess
            import sys

            completed = subprocess.run(
                [
                    sys.executable, str(GENERATOR_PATH),
                    "--start", "-2", "--end", "2",
                    "--format", output_format, "--output", str(output),
                ],
                check=False, capture_output=True, text=True,
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            self.assertIn("Wrote 5 records", completed.stdout)
            return output.read_text(encoding="utf-8")

    def test_csv_output_is_parseable_and_complete(self):
        with tempfile.TemporaryDirectory() as temporary:
            output = Path(temporary) / "integers.csv"
            import subprocess
            import sys

            completed = subprocess.run(
                [sys.executable, str(GENERATOR_PATH), "--start", "-2", "--end", "2",
                 "--format", "csv", "--output", str(output)],
                check=False, capture_output=True, text=True,
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            with output.open(encoding="utf-8", newline="") as stream:
                records = list(csv.DictReader(stream))
            self.assertEqual(len(records), 5)
            self.assertEqual([int(r["integer_value"]) for r in records], [-2, -1, 0, 1, 2])

    def test_jsonl_output_is_parseable_and_complete(self):
        content = self.run_cli("jsonl")
        records = [json.loads(line) for line in content.splitlines()]
        self.assertEqual(len(records), 5)
        self.assertEqual([r["integer_value"] for r in records], [-2, -1, 0, 1, 2])

    def test_cli_rejects_reversed_range(self):
        import subprocess
        import sys

        with tempfile.TemporaryDirectory() as temporary:
            output = Path(temporary) / "should-not-exist.csv"
            completed = subprocess.run(
                [sys.executable, str(GENERATOR_PATH), "--start", "2", "--end", "1",
                 "--output", str(output)],
                check=False, capture_output=True, text=True,
            )
            self.assertNotEqual(completed.returncode, 0)
            self.assertIn("--start must be <=", completed.stderr)
            self.assertFalse(output.exists())


if __name__ == "__main__":
    unittest.main()
