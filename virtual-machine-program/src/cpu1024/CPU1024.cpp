#include "vm1024/CPU1024.hpp"
namespace vm1024 {
U1024 CPU1024::add(const U1024&a,const U1024&b)const{U1024 r; unsigned __int128 carry=0; for(int i=0;i<16;i++){auto s=(unsigned __int128)a.limb[i]+b.limb[i]+carry;r.limb[i]=(std::uint64_t)s;carry=s>>64;} return r;}
U1024 CPU1024::bit_xor(const U1024&a,const U1024&b)const{U1024 r;for(int i=0;i<16;i++)r.limb[i]=a.limb[i]^b.limb[i];return r;}
}
