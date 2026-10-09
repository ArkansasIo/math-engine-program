#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
namespace vm1024 {
struct U1024 { std::array<std::uint64_t,16> limb{}; };
struct V1024 { std::array<std::uint64_t,16> lane{}; };
using Address=std::uint64_t;
}