# AxiomForge API server

TypeScript/Express service for authenticated projects, branch revision history, review and release metadata, jobs, and WebSocket event subscriptions.

## Routes
- `POST /api/v1/auth/register`, `POST /api/v1/auth/login`
- `GET/POST /api/v1/projects`
- `GET/POST/DELETE /api/v1/projects/:projectId/members`
- `GET /api/v1/revisions/:projectId/branches`
- `POST /api/v1/revisions/:projectId/branches/:branchId/revisions`
- `GET/POST/PATCH /api/v1/revisions/:projectId/reviews`
- `GET/POST /api/v1/revisions/:projectId/releases`, plus publish endpoint
- `POST /api/v1/jobs`, `GET /api/v1/jobs/:jobId`
- `GET /api/v1/health/live`, `GET /api/v1/health/ready`
- WebSocket endpoint: `/api/v1/ws`; send `{"type":"subscribe","projectId":"..."}` after connection.

Use `npm install`, `npm run build`, and `npm test`. Database migrations are in `migrations/`. Worker startup: `npm run worker` (script added in package metadata).

**Security note:** the current WebSocket handshake accepts a short-lived access token in the query string; tokens in URLs can leak through logs and should be replaced by a secure one-time ticket flow before production. The worker currently handles only bounded mathematical evaluation and basic file validation; build/test execution requires an isolated sandbox and is intentionally not executed.
