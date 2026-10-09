#pragma once
#include "Types.hpp"
namespace vm1024 {
class CPU1024 {
public:
  U1024 add(const U1024&,const U1024&) const;
  U1024 bit_xor(const U1024&,const U1024&) const;
};
}
