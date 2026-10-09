# v4.1 development platform

## Implemented source foundations
- TypeScript/Express API server with optional TLS termination using configured key/certificate paths.
- PostgreSQL pool and SQL migrations for users, projects, memberships, branches, revisions, reviews, jobs, events, releases, and audit records.
- Password hashing with bcryptjs, short-lived signed bearer tokens, input schemas, and login rate limiting.
- Project creation and listing, branch listing, optimistic revision commits, and job submission/polling.
- In-process event hub and authenticated WebSocket subscriptions to authorized project revision events.
- Docker Compose development environment and CI workflow for C++23 plus TypeScript.

## Operational constraints
- Run SQL migrations before starting the API. The current Compose configuration loads the initial SQL files through PostgreSQL's initialization directory, which runs only for a fresh database volume.
- Set a unique, high-entropy `JWT_SECRET` in every non-local environment. Configure TLS paths or place the service behind a trusted TLS-terminating proxy.
- The WebSocket event hub is in-process and does not survive process restarts or fan out across multiple API instances. PostgreSQL persistence for collaboration events and a shared broker are future hardening work.
- A production job worker, invitation/member-management endpoints, review/release endpoints, refresh-token revocation, CSRF strategy for cookie auth, observability, and formal threat modeling are not complete.
- CI configuration is added, but no remote CI run is claimed by this commit.
