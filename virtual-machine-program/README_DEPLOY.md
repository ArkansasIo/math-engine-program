# Windows Desktop Deployment
Configure and build from a Windows x64 developer shell:
`cmake -S virtual-machine-program -B virtual-machine-program/build -G "Visual Studio 17 2022" -A x64`
`cmake --build virtual-machine-program/build --config Release`
`ctest --test-dir virtual-machine-program/build -C Release --output-on-failure`
Then launch `virtual-machine-program/build/Release/vm1024-dashboard.exe`. The dashboard is native Win32/GDI and the engine remains a software simulation of 1024-bit and quantum hardware.