# Test Plan
## Unit
CPU1024 carry propagation, XOR, GPU vector addition, dot product, virtual memory bounds, instruction decoding, quantum gate normalization, measurement probabilities, and Math Engine operation IDs.
## Integration
Build the static VM library, CLI, and Windows dashboard; run all CTest targets.
## Release
Build Release on Windows x64, execute CTest, launch the dashboard, verify config loading, and archive the dashboard executable with vm.json and ui.json.
## Known limits
Quantum state-vector simulation scales exponentially with qubit count. The current dashboard contains representative telemetry and UI state; binding every panel to live simulation state is a subsequent integration step.