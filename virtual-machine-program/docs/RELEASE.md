# Release Checklist
- Configure with the supported Windows x64 generator.
- Build Release.
- Run all CTest targets.
- Verify the CLI starts with config/vm.json.
- Package the executable and configuration.
- Record the Git commit SHA in the release notes.
- Keep the VM explicitly labeled as a software simulation.
- Do not ship debug symbols or build directories in the production archive.