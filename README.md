# AxiomForge Mathematics Platform

**AxiomForge** is a C++23 mathematics-engine scaffold for a modular, extensible mathematics knowledge platform.

- **Developer:** AxiomForge Labs
- **Version:** 0.1.0-dev
- **Build:** 1001
- **Build ID:** AXF-0.1.0-dev-1001
- **Product ID:** `com.axiomforge.math-platform`
- **Primary language:** C++23
- **License:** MIT
- **Project codename:** Master Mathematics

## Current scope

- CMake-based C++23 project structure
- Arithmetic operations and number-theory utilities
- A mathematics knowledge graph and query interface
- Command-line application and console-style GUI shell
- Menu/window abstractions and mock graphics renderer
- Build metadata, project manifest, and validation script
- Update/patch policy documentation and example patch manifest
- OpenAPI v1 contract draft
- Starter Prolog mathematics rules and Lua example scripts

## Build

Requirements: CMake 3.20+ and a C++23-capable compiler.

```sh
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build --output-on-failure
```

Run the CLI executable produced by the build. Use `--help` or `help` if supported by the selected target.

## Project status

This is an **early development scaffold**, not a complete computer algebra system or production release. The GUI and renderer are placeholders; Lua and Prolog are not yet integrated into the C++ runtime; the OpenAPI file is a contract draft rather than a running HTTP server; and the update manager does not yet provide signed, networked patch installation. Symbolic calculus, arbitrary precision, and the comprehensive mathematics graph remain planned work.

See `docs/` for identity/versioning, API, security, build/release, project-tree, and update-policy notes.

## Repository

This repository is the canonical source location for the AxiomForge Mathematics Platform. Changes should preserve the distinction between implemented functionality and planned capabilities.
