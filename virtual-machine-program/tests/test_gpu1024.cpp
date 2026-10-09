#include "vm1024/GPU1024.hpp"
#include <cassert>
int main(){vm1024::GPU1024 g;vm1024::V1024 a{},b{};for(int i=0;i<16;i++){a.lane[i]=i;b.lane[i]=2*i;}auto r=g.add(a,b);assert(r.lane[7]==21);auto d=g.dot(a,b);assert(d.limb[0]==1240);return 0;}