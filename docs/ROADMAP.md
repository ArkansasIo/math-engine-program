# Implementation roadmap

## v0.1 development baseline
- [x] C++23 arithmetic, number theory, graph, query CLI
- [x] Polynomial algebra and polynomial derivative/antiderivative
- [x] Matrix operations, descriptive statistics, combinatorics, propositional logic, finite sets
- [x] Numerical differentiation, Simpson integration, bisection root finding
- [x] Basic geometry, 3D vectors, common unit conversions, complex number helpers
- [x] TypeScript API foundation, PostgreSQL schema, project roles, branch revisions, review/release metadata, job worker
- [x] React development client and CI/deployment scaffolding

## Remaining for production readiness
- [ ] Run and fix remote CI on the integrated branch; add API integration tests against a disposable PostgreSQL database.
- [ ] Implement account verification, recovery, token revocation, robust abuse controls, security review, and observability.
- [ ] Replace query-string WebSocket token with a one-time ticket; implement durable event replay and multi-instance pub/sub.
- [ ] Complete branch create/rename/merge, revision diff, conflict resolution, review/release UI, and artifact signing.
- [ ] Add isolated build/test workers with resource limits; never execute user code in the API process.
- [ ] Build full symbolic expression parsing, simplification, limits, differentiation/integration, equation solving, arbitrary precision, and theorem/rule engine.
- [ ] Integrate Lua/Prolog with a permissioned plugin runtime and sandbox.
- [ ] Implement native GUI and production 2D/3D visualization.
- [ ] Implement signed update manifests, artifact hashes, staged rollout, rollback, and atomic patch application.
- [ ] Expand tests, benchmarks, documentation, packaging, accessibility, and release process.
