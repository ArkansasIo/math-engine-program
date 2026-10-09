# Build and release

Requirements: CMake 3.20+ and a compiler with C++23 support.

```sh
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build --output-on-failure
```

The current CMake build compiles the CLI, arithmetic, number theory, and knowledge graph foundations. Release signing, installers, native GUI packaging, and update delivery are not yet implemented.
