# File Manifest
## Build and automation
- CMakeLists.txt: C++23 library, CLI, Windows dashboard, CTest registration.
- .github/workflows/windows.yml: Windows x64 build, tests, ZIP artifact.
- scripts/build_windows.ps1 and scripts/build_msvc.bat: local Windows build/test.
- scripts/package_release.ps1: local package helper.
- config/build.json, config/vm.json, config/ui.json: build and runtime settings.
## Source
- include/vm1024: 1024-bit values, CPU/GPU APIs, memory, runtime and instruction definitions.
- include/quantum: state-vector, gates and measurement APIs.
- include/math: Math Engine operation ID bridge.
- src: CPU, GPU, memory, decoder, quantum simulation, bridge, CLI and Win32 dashboard.
## Validation
- tests: smoke, decoder, CPU arithmetic, GPU vectors, memory, quantum gates/probabilities, math bridge.
- examples and assembler: illustrative assembly and opcode mapping.
## Documentation
See ARCHITECTURE.md, DESIGN.md, API.md, USER_GUIDE.md, TEST_PLAN.md, TEST_BUILD.md, DEPLOYMENT.md, RELEASE.md, RELEASE_NOTES.md, SECURITY.md, UI.md, ASSET_GUIDE.md, BUILD_MATRIX.md, ROADMAP.md, and IMPLEMENTATION.md.