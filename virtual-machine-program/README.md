# Virtual Machine Program

Hybrid 64-bit Windows-hosted virtual computer integrating the repository Math Engine with a simulated 1024-bit CPU/GPU and simulated quantum subsystem.

## Current implementation

- C++23/CMake engine library, CLI, and native Win32/GDI dashboard target.
- 1024-bit unsigned value represented by sixteen 64-bit limbs, with carry-aware addition and XOR.
- 16-lane vector addition and a baseline dot-product operation.
- Bounds-checked virtual byte memory.
- Initial V1024-QISA opcode decoder.
- State-vector initialization, normalization, Hadamard, Pauli-X, CNOT, and measurement-probability functions.
- Math Engine operation-name bridge.
- CTest regression targets and Windows x64 GitHub Actions packaging workflow.

## Important scope statement

This is a user-space software simulation, not a hypervisor. The 1024-bit and quantum processors are virtual models; they do not imply physical 1024-bit or quantum hardware. The dashboard is currently a visual shell, and not every toolbar action or telemetry panel is connected to live runtime state. The decoder exists, but a complete instruction execution loop and binary assembler are still future work.

## Build on Windows x64

Install Visual Studio 2022 with the C++ desktop workload and CMake 3.25 or later, then run from the repository root:

```powershell
cmake -S virtual-machine-program -B virtual-machine-program/build -G "Visual Studio 17 2022" -A x64
cmake --build virtual-machine-program/build --config Release --parallel
ctest --test-dir virtual-machine-program/build -C Release --output-on-failure
```

Launch the desktop UI at `virtual-machine-program/build/Release/vm1024-dashboard.exe`, or the CLI at `virtual-machine-program/build/Release/vm1024-cli.exe`.

## Build on Linux

The engine and CLI are intended to be portable. The Win32 dashboard is built only on Windows.

```sh
cmake -S virtual-machine-program -B virtual-machine-program/build
cmake --build virtual-machine-program/build --parallel
ctest --test-dir virtual-machine-program/build --output-on-failure
```

## Windows test build artifact

The GitHub Actions workflow at `.github/workflows/windows.yml` builds Release, runs CTest, and attempts to package the dashboard, CLI, and configuration as `VirtualMachine1024-Windows-x64.zip`. Treat the ZIP as verified only after the workflow succeeds. This conversation has not independently run MSVC or confirmed the artifact.

## Repository map

- `include/vm1024/`: integer/vector types, CPU/GPU, memory, decoder, runtime.
- `include/quantum/`: quantum register, gates, measurement.
- `include/math/`: Math Engine bridge API.
- `src/`: implementation and entry points.
- `tests/`: regression tests.
- `assembler/`, `isa/`, `examples/`: initial ISA tooling and sample programs.
- `assets/ui/`, `config/`: dashboard branding and settings.
- `scripts/`: Windows build/package scripts.
- `docs/`: architecture, design, API, tests, deployment, release and roadmap.

See `docs/KNOWN_ISSUES.md` and `docs/ROADMAP.md` for explicit limitations and next steps.