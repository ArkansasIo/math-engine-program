# Jobs and workers

Jobs are persisted in PostgreSQL with queued, running, succeeded, failed, or cancelled status. The development worker claims one queued job with SELECT FOR UPDATE SKIP LOCKED, records start time, executes supported work, and records output/error plus finish time.

Currently supported:
- math.evaluate: bounded arithmetic and primality operations.
- file.validate: basic payload-shape check only.

Build and test job types are accepted by the API schema but intentionally fail in the worker because no isolated build sandbox is implemented. Do not execute submitted source code inside the API or worker process. Production support requires sandboxing, CPU/memory/time limits, workspace isolation, network policy, artifact hashing, retries, cancellation, and job idempotency.
