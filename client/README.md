# AxiomForge web client

React + TypeScript + Vite development workspace with Math, Team, Debug, Build, and Review modes.

```sh
npm install
cp .env.example .env
npm run dev
```

The Vite development server runs at `http://localhost:3000` and expects the API at `http://localhost:8080/api/v1` by default.

The client currently supports account login/registration, project creation/listing, branch selection, JSON document revision commits, bounded math job submission, and a starter WebSocket event connection. Review/release management is implemented at the metadata/workflow level; full revision-diff visualization and artifact downloads are still planned. Access tokens are held in memory and are not persisted; the current WebSocket API passes the short-lived token in the URL, which should be replaced with one-time connection tickets before production.
