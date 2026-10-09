cmake_minimum_required(VERSION 3.20)
project(AxiomForge VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(AXIOMFORGE_VERSION "0.1.0-dev")
set(AXIOMFORGE_BUILD_NUMBER "1001")
set(AXIOMFORGE_PRODUCT_ID "com.axiomforge.math-platform")
configure_file(include/axiomforge/build_info.hpp.in generated/axiomforge/build_info.hpp @ONLY)
add_library(axiomforge_core
  src/core/graph.cpp
  src/math/arithmetic.cpp
  src/math/number_theory.cpp
  src/api/api_info.cpp
  src/system/update_manager.cpp
  src/terminal/terminal.cpp
  src/ui/menu.cpp
  src/ui/window.cpp
  src/graphics/mock_renderer.cpp
)
target_include_directories(axiomforge_core PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/generated")
if(MSVC)
  target_compile_options(axiomforge_core PRIVATE /W4 /permissive-)
else()
  target_compile_options(axiomforge_core PRIVATE -Wall -Wextra -Wpedantic)
endif()
add_executable(axiomforge_cli apps/cli/main.cpp)
target_link_libraries(axiomforge_cli PRIVATE axiomforge_core)
add_executable(axiomforge_gui_shell apps/gui/main.cpp)
target_link_libraries(axiomforge_gui_shell PRIVATE axiomforge_core)
enable_testing()
add_executable(axiomforge_tests tests/test_main.cpp)
target_link_libraries(axiomforge_tests PRIVATE axiomforge_core)
add_test(NAME axiomforge_tests COMMAND axiomforge_tests)
