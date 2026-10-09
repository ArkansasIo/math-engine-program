PRAGMA foreign_keys=ON;

CREATE TABLE IF NOT EXISTS term_families (
  id TEXT PRIMARY KEY,
  name TEXT NOT NULL,
  symbol TEXT NOT NULL,
  definition TEXT NOT NULL,
  domain_name TEXT NOT NULL,
  generator TEXT NOT NULL
);

CREATE TABLE IF NOT EXISTS term_records (
  id TEXT PRIMARY KEY,
  family_id TEXT NOT NULL REFERENCES term_families(id),
  canonical_value TEXT NOT NULL,
  integer_value TEXT,
  sign_class TEXT,
  metadata_json TEXT NOT NULL DEFAULT '{}'
);

CREATE TABLE IF NOT EXISTS dataset_specs (
  id TEXT PRIMARY KEY,
  name TEXT NOT NULL,
  domain_name TEXT NOT NULL,
  parameters_json TEXT NOT NULL,
  invariant TEXT NOT NULL
);

CREATE TABLE IF NOT EXISTS materialized_windows (
  id TEXT PRIMARY KEY,
  dataset_id TEXT NOT NULL REFERENCES dataset_specs(id),
  start_value TEXT NOT NULL,
  end_value TEXT NOT NULL,
  row_count INTEGER NOT NULL CHECK (row_count >= 0),
  created_utc TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE INDEX IF NOT EXISTS idx_term_records_family ON term_records(family_id);
CREATE INDEX IF NOT EXISTS idx_term_records_sign ON term_records(sign_class);
CREATE INDEX IF NOT EXISTS idx_term_records_value ON term_records(integer_value);
