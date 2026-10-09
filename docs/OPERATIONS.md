# Operations guide

## Health
- Liveness: GET /api/v1/health/live
- Readiness: GET /api/v1/health/ready (includes a database ping)
- Every API response carries X-Request-Id; include it in incident reports.

## Migrations
The Compose migration service runs ordered SQL migrations before the API and worker. Inspect the schema_migrations table when using the explicit migration runner. Test upgrades against a copy of the existing schema before deployment.

## Audit and collaboration
Owners can read project audit entries through GET /api/v1/audit/:projectId. Authorized members can retrieve persisted collaboration events through GET /api/v1/events/:projectId. The WebSocket process broadcasts new events locally; multi-instance deployments need shared fanout.

## Backup and recovery
Use the database provider's consistent backup mechanism. Periodically restore into an isolated database and verify projects, revisions, memberships, releases, and audit records. Artifact storage is not implemented yet, so release records currently store metadata rather than downloadable artifacts.

## Incident response
Rotate exposed credentials, revoke or replace JWT signing secrets, preserve logs and request IDs, restrict affected accounts, and document the timeline. Refresh-token revocation and centralized session invalidation are not implemented in this development version.
