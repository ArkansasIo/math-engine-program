# AxiomForge Mathematics Platform

**AxiomForge** is a C++23 mathematics core and collaborative mathematical development platform.

- **Developer:** AxiomForge Labs
- **Version:** 0.1.0-dev
- **Build:** 1001 · **Build ID:** `AXF-0.1.0-dev-1001`
- **Product ID:** `com.axiomforge.math-platform`
- **API:** AxiomForge Math API v1 at `/api/v1`
- **License:** MIT
- **Project codename:** Master Mathematics

## Platform components

- **C++23 core:** arithmetic, number theory, knowledge graph, graph traversal/query, CLI, UI/renderer abstractions.
- **TypeScript API:** login/registration, short-lived bearer tokens, project CRUD foundations, role checks, branch/revision commits with optimistic concurrency, reviews, releases, job submission/polling, synchronous math evaluation, event history, and owner-only audit queries.
- **PostgreSQL:** migrations for users, projects, memberships, branches, revisions, reviews, jobs, collaboration events, releases, and audit log.
- **Web client:** React + TypeScript workspace with Math, Team, Debug, Build, and Review modes.
- **Collaboration:** WebSocket event relay for authorized project subscriptions.
- **Worker:** bounded mathematical evaluation and basic file validation. Arbitrary builds or submitted code are not executed.
- **Automation:** GitHub Actions CI, Dockerfiles, and Docker Compose development stack.
- **Scripting/documentation:** starter Prolog rules, illustrative Lua example, OpenAPI draft, build identity and update-policy docs.

## Quick start

### C++23 core
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

### Full development stack
Requirements: Docker Compose v2.

```sh
docker compose up --build
```

- Web client: `http://localhost:3000`
- API liveness: `http://localhost:8080/api/v1/health/live`
- API readiness: `http://localhost:8080/api/v1/health/ready`

The default Compose credentials/secrets are for local development only. Override `POSTGRES_PASSWORD` and `JWT_SECRET` before using the stack outside a private development environment. The Compose stack runs an idempotent migration service before starting the API and worker. The PostgreSQL initialization scripts also run on a fresh volume. For manual migration or troubleshooting, see [docs/DATABASE_MIGRATIONS.md](docs/DATABASE_MIGRATIONS.md).

## Project status and limits

This remains a development platform, not a production release or a complete computer algebra system. The C++ GUI/renderer are mock abstractions; the React client provides a JSON document editor, branch/revision workflow, team membership controls, review decisions, release-draft creation, and bounded job controls. A full revision-diff/merge UI and production artifact pipeline remain incomplete. The API's event hub is in-process (not multi-instance durable), WebSocket authentication currently uses a short-lived token in the URL, and the job worker does not run arbitrary builds or code. Account recovery, refresh-token revocation, cross-instance live event fanout, signed release artifacts, secure automatic updates, arbitrary precision, symbolic calculus, and full mathematics taxonomy remain future work.

See [docs/CLI_REFERENCE.md](docs/CLI_REFERENCE.md), [docs/MATHEMATICS_MODULES.md](docs/MATHEMATICS_MODULES.md), [docs/V4_1_IMPLEMENTATION.md](docs/V4_1_IMPLEMENTATION.md), [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md), [docs/SECURITY_REVIEW.md](docs/SECURITY_REVIEW.md), and [server/README.md](server/README.md) for details.
