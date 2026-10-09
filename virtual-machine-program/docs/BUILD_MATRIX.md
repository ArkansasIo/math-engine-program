# Build Matrix
| Target | Platform | Toolchain | Output |
|---|---|---|---|
| vm1024 | Windows/Linux | C++23 + CMake | static library |
| vm1024-cli | Windows/Linux | C++23 + CMake | CLI executable |
| vm1024-dashboard | Windows x64 | MSVC + Win32/GDI | desktop executable |
| smoke/decoder/CPU/GPU/memory/quantum/math tests | Windows/Linux | CTest | test executables |
| assembler | Python 3 | standard library | assembler utility |
The Windows dashboard is the primary distributable application.