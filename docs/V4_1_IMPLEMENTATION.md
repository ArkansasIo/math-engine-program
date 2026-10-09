# v4.1 development platform

## Implemented source foundations
- TypeScript/Express API server with optional TLS termination using configured key/certificate paths.
- PostgreSQL pool and SQL migrations for users, projects, memberships, branches, revisions, reviews, jobs, events, releases, and audit records.
- Password hashing with bcryptjs, short-lived signed bearer tokens, input schemas, and login rate limiting.
- Project creation and listing, branch listing, optimistic revision commits, and job submission/polling.
- Transactionally persisted collaboration event log, authorized WebSocket subscriptions, bounded replay of the latest 100 events, and duplicate suppression during replay.
- Docker Compose development environment and CI workflow for C++23 plus TypeScript.

## Operational constraints
- Run SQL migrations before starting the API. The current Compose configuration loads the initial SQL files through PostgreSQL's initialization directory, which runs only for a fresh database volume.
- Set a unique, high-entropy `JWT_SECRET` in every non-local environment. Configure TLS paths or place the service behind a trusted TLS-terminating proxy.
- Event history is persisted in PostgreSQL and can be replayed on subscription, but live fanout remains process-local. Multiple API instances still need a shared broker or PostgreSQL LISTEN/NOTIFY strategy.
- A production build/test worker, account invitations for users who have not registered, refresh-token revocation, a cookie-auth CSRF strategy, observability, and formal threat modeling are not complete. Membership, review, and release metadata endpoints are implemented, but artifact signing/distribution and a full revision-diff UI are not.
- CI configuration is added, but no remote CI run is claimed by this commit.
