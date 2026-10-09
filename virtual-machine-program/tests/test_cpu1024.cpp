#include "vm1024/CPU1024.hpp"
#include <cassert>
#include <cstdint>
int main(){vm1024::CPU1024 c;vm1024::U1024 a{},b{};a.limb[0]=UINT64_MAX;b.limb[0]=1;auto r=c.add(a,b);assert(r.limb[0]==0);assert(r.limb[1]==1);auto x=c.bit_xor(a,b);assert(x.limb[0]==(UINT64_MAX^1ULL));return 0;}