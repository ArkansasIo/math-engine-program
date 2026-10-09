# Architecture

- **C++23 core:** arithmetic, number theory, knowledge graph, query engine, terminal/UI abstractions.
- **API service:** TypeScript/Express REST endpoints, authentication, project authorization, revision commits, job metadata, WebSocket event relay.
- **PostgreSQL:** durable identity, membership, project, branch, revision, review, job, release, event, and audit tables.
- **Clients:** CLI and console shell exist as development interfaces; a native graphical editor and browser client remain planned.
- **Automation:** GitHub Actions compiles and tests the C++ core and type-checks/builds the API.

Trust boundaries: clients are untrusted; authorization is checked server-side for project resources. Do not expose PostgreSQL directly to clients. Terminate TLS at the API or a trusted proxy. Treat submitted mathematical documents and job input as untrusted data.
