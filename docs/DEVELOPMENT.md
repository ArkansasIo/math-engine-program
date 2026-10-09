# Development setup

## C++23 core
```sh
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build --output-on-failure
```

## API server
```sh
cp server/.env.example server/.env
# Set a unique JWT_SECRET and the local PostgreSQL URL.
docker compose up --build
```

Apply migrations to an existing database in order:
```sh
psql "$DATABASE_URL" -f server/migrations/001_initial.sql
psql "$DATABASE_URL" -f server/migrations/002_realtime_and_releases.sql
```

API liveness is available at `GET /api/v1/health/live`; readiness checks PostgreSQL at `GET /api/v1/health/ready`. Register and log in at `/api/v1/auth/register` and `/api/v1/auth/login`. Use the returned access token as a Bearer token for protected routes.

See [DATABASE_MIGRATIONS.md](DATABASE_MIGRATIONS.md) for the automatic Compose migration service and manual migration command.
