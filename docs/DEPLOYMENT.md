# Deployment

## Local development
Use Docker Compose to start PostgreSQL, run migrations, and start the API, worker, and React client.

```sh
docker compose up --build
```

## Production requirements
- Supply unique secrets through a secret manager, never from committed defaults.
- Expose the client/API only through HTTPS/WSS and configure exact CORS origins.
- Use managed PostgreSQL with least-privilege credentials, backups, monitoring, and tested restores.
- Run migration jobs as a controlled deployment step and review schema compatibility.
- Use a shared event broker for multiple API instances.
- Do not enable build/test execution until sandboxing and resource quotas are in place.
- Sign release artifacts and verify hashes before distributing them.
- Configure structured logs, request IDs, health probes, rate limits, dependency updates, and alerting.

The current Docker Compose stack is for development and is not a production deployment recipe.
