#pragma once
#include "Instruction.hpp"
#include <cstdint>
namespace vm1024 {
Instruction decode(std::uint32_t word);
}