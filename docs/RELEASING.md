# Release process

A tag matching v* triggers the GitHub Actions workflow in .github/workflows/release.yml. The workflow builds and tests the C++23 core, type-checks/builds the React client, compiles the TypeScript API, and attaches separate tarballs for the C++ binaries, static web client, and API distribution to a GitHub Release.

Before creating a release tag:
1. Confirm the main-branch CI workflow is green.
2. Review the security checklist and release notes.
3. Verify migrations against both a fresh database and a prior-version database.
4. Set the release version consistently in product metadata and package metadata.
5. Do not publish a production release while authentication recovery, durable collaboration fanout, sandboxed build workers, and signed update artifacts remain incomplete.

Tag-based packaging does not itself make the application production-ready and does not sign binaries or update artifacts.
