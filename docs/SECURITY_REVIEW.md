# Deployment security checklist

- [ ] Replace all development secrets and use a unique high-entropy JWT secret.
- [ ] Enforce HTTPS/WSS and configure trusted proxy headers explicitly.
- [ ] Restrict CORS to exact production origins.
- [ ] Add account verification, password reset, and access-token revocation before public signup.
- [ ] Add audit events for account, membership, revision, review, release, and permission changes.
- [ ] Configure database least-privilege roles, backups, retention, and restore tests.
- [ ] Add durable cross-instance WebSocket event fanout and reconnect/resume protocol.
- [ ] Add queue workers with retries, timeouts, idempotency keys, and sandboxed execution.
- [ ] Apply request-size limits, rate limits, dependency scanning, and secret scanning.
- [ ] Run migration, API, authorization, concurrency, and disaster-recovery tests before production.
