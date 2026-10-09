# V1024-QISA

Initial instruction-set definition for the hybrid virtual machine.

## Classical

IADD1024 R1,R2,R3
ISUB1024 R4,R1,R2
IMUL1024 R5,R1,R2
IDIV1024 R6,R5,R2
AND1024 R7,R5,R6
OR1024 R8,R5,R6
XOR1024 R9,R5,R6

## Vector / GPU

VADD1024 V1,V2,V3
VMUL1024 V4,V1,V2
DOT1024 R10,V4,V5
MATMUL1024 M3,M1,M2

## Quantum

QALLOC Q0-Q63
H Q0
X Q1
CNOT Q0,Q1
RZ Q2,theta
MEASURE Q0,R11
QFREE Q0-Q63

These mnemonics are an architectural specification, not yet a claim of a finished hardware implementation.
