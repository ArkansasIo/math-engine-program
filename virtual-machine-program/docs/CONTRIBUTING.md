# Contributing
1. Keep the portable engine in C++23 and isolate Win32-only code under src/ui.
2. Add regression tests for every arithmetic, decoding, memory, or quantum change.
3. Use bounds checks for guest memory and limits for state-vector allocations.
4. Do not describe simulated hardware as physical hardware.
5. Build and test locally with scripts/build_windows.ps1 or the documented CMake commands.
6. Keep UI assets redistributable and document new assets in assets/ui/ASSET_MANIFEST.md.
7. Update the relevant architecture/API/release docs when public interfaces change.