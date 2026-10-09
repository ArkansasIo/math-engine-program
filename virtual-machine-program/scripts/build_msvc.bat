@echo off
setlocal
set ROOT=%~dp0..
cmake -S "%ROOT%" -B "%ROOT%\build" -G "Visual Studio 17 2022" -A x64
if errorlevel 1 exit /b %errorlevel%
cmake --build "%ROOT%\build" --config Release
ctest --test-dir "%ROOT%\build" -C Release --output-on-failure