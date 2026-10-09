#pragma once
#include "CPU1024.hpp"
#include "GPU1024.hpp"
#include "Memory.hpp"
#include "Instruction.hpp"
namespace vm1024 { class VMRuntime { CPU1024 cpu_; GPU1024 gpu_; Memory memory_; public: explicit VMRuntime(std::size_t bytes=1024*1024):memory_(bytes){} void reset(){memory_=Memory(memory_.size());} CPU1024& cpu() noexcept{return cpu_;} GPU1024& gpu() noexcept{return gpu_;} Memory& memory() noexcept{return memory_;} }; }