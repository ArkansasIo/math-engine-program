# Known Issues and Scope
- The project is a software simulator, not a hypervisor or a physical 1024-bit/quantum computer.
- The Win32 dashboard currently draws a visual shell; toolbar labels are not yet connected to engine actions, and several telemetry values are illustrative rather than live.
- The instruction decoder recognizes opcode words, but a complete CPU instruction execution loop and assembler binary encoder are not implemented.
- GPU arithmetic is a baseline model, not a graphics API or a massively parallel device scheduler.
- Quantum simulation uses state vectors and has exponential memory/time growth. Allocation is capped defensively; choose small qubit counts for tests.
- The Math Engine bridge currently maps stable operation names; linking the repository's full mathematical dataset/runtime remains integration work.
- Windows CI must pass before a compiled artifact can be called verified. No binary is claimed as built by this documentation change.