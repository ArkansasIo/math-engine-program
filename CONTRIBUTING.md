# Contributing

1. Create a feature branch and keep changes focused.
2. Run the C++ configure/build/test workflow.
3. Run server install, build, typecheck, and tests; verify SQL migrations against PostgreSQL.
4. Run client install, typecheck, and production build.
5. Update docs, OpenAPI, migration notes, and tests for behavior changes.
6. Do not commit secrets, generated dependency folders, or local environment files.
7. Mark placeholder behavior clearly; do not label a draft subsystem production-ready.

## Review checklist
- Authorization is enforced server-side for every project-scoped operation.
- Database changes are parameterized and migrations are repeatable.
- Numerical functions document precision, domain, and overflow limitations.
- Async jobs are bounded, observable, and idempotent where applicable.
- Errors do not expose secrets or stack traces to clients.
