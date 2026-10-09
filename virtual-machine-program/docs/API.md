# API Surface
CPU1024: add and bit_xor operate on U1024, represented by sixteen 64-bit limbs.
GPU1024: vector addition and baseline dot product operate on sixteen-lane V1024 values.
Memory: bounds-checked byte reads/writes and virtual-memory sizing.
Quantum: QubitRegister, Hadamard, Pauli-X, CNOT, and measurement probability APIs.
Math Bridge: stable operation identifiers expose VM operations to the AxiomForge Math Engine registry.