# Deploy the Virtual Machine
From a Windows x64 developer shell:
`powershell -ExecutionPolicy Bypass -File .\scripts\build_windows.ps1`
Then run:
`.uild\Release\vm1024-cli.exe`
For a distributable archive:
`powershell -ExecutionPolicy Bypass -File .\scripts\package_release.ps1`
The project remains a user-space simulator hosted by Windows x64.