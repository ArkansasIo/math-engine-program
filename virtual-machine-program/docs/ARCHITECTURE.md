# Virtual Machine Architecture

## System layers

Windows x64 host -> Virtual Machine Runtime -> Classical 1024-bit subsystem + Quantum subsystem -> Unified Math Engine.

## Math Engine bridge

The bridge maps VM instruction/function IDs to mathematical operations represented by the Math Engine repository.

ID families:
- MATH-* — classical mathematics
- V1024-* — 1024-bit arithmetic/vector operations
- QMATH-* — quantum mathematics
- QGATE-* — quantum gate primitives

The bridge preserves deterministic inputs, precision metadata, operation IDs, verification status and reproducible test vectors.

## Quantum simulation model

The initial implementation is a software simulator. A qubit register can be represented by a state vector or density matrix. Gates are complex/unitary operators, and measurement produces probabilistic outcomes according to the simulated quantum state.

## CPU/GPU relationship

The vCPU provides control, scalar arithmetic and virtual machine execution. The vGPU provides parallel vector/matrix workloads. The quantum subsystem provides a separate instruction domain while sharing memory-management, job, logging and Math Engine interfaces.

## Future hardware path

1. SystemVerilog reference RTL.
2. FPGA implementations.
3. External quantum-computing backends.
4. Native hardware acceleration where available.
