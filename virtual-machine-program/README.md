# Virtual Machine Program

Hybrid 64-bit Windows-hosted virtual computer integrating the AxiomForge Math Engine with a simulated 1024-bit CPU/GPU and simulated quantum CPU/GPU.

## Architecture

- Host: 64-bit Windows
- vCPU: 1024-bit integer/vector datapath
- vGPU: 1024-bit vector, matrix and graphics accelerator model
- Quantum CPU/QPU: qubit-register, state-vector and circuit simulation
- Quantum GPU/QPU accelerator: parallel quantum-state and circuit workloads
- Unified Math Engine: classical, 1024-bit, complex, matrix, tensor and quantum mathematics
- Tooling: assembler, instruction definitions, simulator, tests and examples

The virtual machine is a software simulation. The 1024-bit and quantum processors do not imply native 1024-bit or quantum hardware in the Windows host.

## Integration

The VM consumes the repository's existing mathematical foundation under data/universal-mathematics/ and is designed to share mathematical operation IDs, schemas, deterministic datasets and verification metadata.

## Source layout

virtual-machine-program/
  include/vm1024/
  include/quantum/
  include/math/
  src/cpu1024/
  src/gpu1024/
  src/quantum_cpu/
  src/quantum_gpu/
  src/memory/
  src/machine/
  src/math_bridge/
  isa/
  assembler/
  firmware/
  tests/
  examples/
  docs/

## Build direction

Implementation target: C++23 with CMake on 64-bit Windows. Python remains available for dataset generation and validation, and SystemVerilog can later provide reference RTL for selected CPU/GPU blocks.
