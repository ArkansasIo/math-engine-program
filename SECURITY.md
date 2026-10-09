# Security policy

AxiomForge is a development scaffold and must not be assumed production-secure.

## Reporting
Do not publish exploitable vulnerabilities, credentials, or private user data in public issues. Contact the repository maintainer privately through the GitHub account's available contact channel and include affected commit, reproduction steps, impact, and a proposed mitigation.

## Current security limitations
- The WebSocket connection currently passes a short-lived bearer token in its query string; use only in development until a one-time ticket flow is implemented.
- Account recovery, email verification, and token revocation are not implemented.
- Live event fanout is process-local; persisted events can be replayed, but multiple server instances do not share live events yet.
- Build/test job kinds are not executed by the worker. Do not add arbitrary code execution without sandboxing and resource limits.
- Update manifests and patch installation are not cryptographically signed/verified.
