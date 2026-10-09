#pragma once
#include "Types.hpp"
#include <vector>
namespace vm1024 {
class Memory {
  std::vector<std::uint8_t> data_;
public:
  explicit Memory(std::size_t bytes);
  std::uint8_t read8(Address) const;
  void write8(Address,std::uint8_t);
};
}
