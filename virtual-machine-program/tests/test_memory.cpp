#include "vm1024/Memory.hpp"
#include <cassert>
int main(){vm1024::Memory m(64);m.write8(7,0xA5);assert(m.read8(7)==0xA5);assert(m.size()==64);return 0;}