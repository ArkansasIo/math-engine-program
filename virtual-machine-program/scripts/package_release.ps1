$ErrorActionPreference="Stop"
$root=Split-Path $PSScriptRoot -Parent
$build="$root/build"
cmake --build $build --config Release
ctest --test-dir $build -C Release --output-on-failure
$out="$root/dist/VirtualMachine1024"
New-Item -ItemType Directory -Force -Path $out | Out-Null
Copy-Item "$build/Release/vm1024-cli.exe" $out
Copy-Item "$root/config/vm.json" $out
Copy-Item "$root/README.md" $out
Compress-Archive -Path "$out/*" -DestinationPath "$root/dist/VirtualMachine1024-windows-x64.zip" -Force
Write-Host "Package: $root/dist/VirtualMachine1024-windows-x64.zip"