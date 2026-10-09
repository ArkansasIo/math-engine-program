#include "vm1024/Decoder.hpp"
#include <cassert>
int main(){const auto i=vm1024::decode(0x10000102u);assert(i.opcode==vm1024::Opcode::IADD1024);assert(i.a==1);assert(i.b==2);return 0;}