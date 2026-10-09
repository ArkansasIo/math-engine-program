cmake_minimum_required(VERSION 3.25)
project(VirtualMachine1024 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(vm1024
  src/cpu1024/CPU1024.cpp
  src/gpu1024/GPU1024.cpp
  src/memory/Memory.cpp
  src/quantum_cpu/QubitRegister.cpp
  src/quantum_cpu/QuantumCircuit.cpp
  src/math_bridge/MathBridge.cpp)
target_include_directories(vm1024 PUBLIC include)
add_executable(vm1024-cli src/main.cpp)
target_link_libraries(vm1024-cli PRIVATE vm1024)
enable_testing()
add_executable(vm1024-smoke tests/test_smoke.cpp)
target_link_libraries(vm1024-smoke PRIVATE vm1024)
add_test(NAME vm1024_smoke COMMAND vm1024-smoke)
