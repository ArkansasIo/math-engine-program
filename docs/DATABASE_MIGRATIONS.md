# Database migrations

Migration SQL files are stored in server/migrations and numbered for deterministic order.

For a fresh local Docker Compose database, PostgreSQL's initialization entrypoint runs the SQL files when the database volume is first created. For an existing database, use the TypeScript migration runner:

```sh
cd server
npm install
npm run build
DATABASE_URL=postgres://axiomforge:password@localhost:5432/axiomforge npm run migrate
```

The runner tracks successfully applied filenames in schema_migrations and applies each migration in a transaction. Keep migrations additive and forward-compatible; test against both an empty database and a database containing the previous released schema before shipping changes.
