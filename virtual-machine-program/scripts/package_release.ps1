$ErrorActionPreference = "Stop"
$root = Split-Path $PSScriptRoot -Parent
$build = Join-Path $root "build"
cmake --build $build --config Release --parallel
ctest --test-dir $build -C Release --output-on-failure
$out = Join-Path $root "dist/VirtualMachine1024-Windows-x64"
New-Item -ItemType Directory -Force -Path $out | Out-Null
Copy-Item (Join-Path $build "Release/vm1024-dashboard.exe") $out
Copy-Item (Join-Path $build "Release/vm1024-cli.exe") $out
Copy-Item (Join-Path $root "config/vm.json") $out
Copy-Item (Join-Path $root "config/ui.json") $out
Copy-Item (Join-Path $root "README.md") $out
Copy-Item (Join-Path $root "CHANGELOG.md") $out
Copy-Item (Join-Path $root "assets") (Join-Path $out "assets") -Recurse -Force
Copy-Item (Join-Path $root "docs") (Join-Path $out "docs") -Recurse -Force
$zip = Join-Path $root "dist/VirtualMachine1024-Windows-x64.zip"
Compress-Archive -Path (Join-Path $out "*") -DestinationPath $zip -Force
Write-Host "Package: $zip"
