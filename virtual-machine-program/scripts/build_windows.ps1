$ErrorActionPreference="Stop"
$root=Split-Path $PSScriptRoot -Parent
cmake -S $root -B "$root/build" -G "Visual Studio 17 2022" -A x64
cmake --build "$root/build" --config Release
ctest --test-dir "$root/build" -C Release --output-on-failure