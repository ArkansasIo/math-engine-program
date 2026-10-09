#include "vm1024/Decoder.hpp"
#include <stdexcept>
namespace vm1024 {
Instruction decode(std::uint32_t word) {
 const auto raw=static_cast<std::uint16_t>((word>>16)&0xffffu);
 switch(raw) {
 case 0x1000: case 0x1001: case 0x1002: case 0x1003:
 case 0x2000: case 0x2001: case 0x2002: case 0x2003:
 case 0x3000: case 0x3001: case 0x3002: case 0x3003:
 case 0x3004: case 0x3005: case 0x3006:
   return Instruction{static_cast<Opcode>(raw),
     static_cast<std::uint8_t>((word>>8)&0xffu),
     static_cast<std::uint8_t>(word&0xffu),0};
 default: throw std::invalid_argument("unknown V1024 opcode");
 }
}
}