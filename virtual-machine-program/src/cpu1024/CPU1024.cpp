#include "vm1024/CPU1024.hpp"
namespace vm1024 {
U1024 CPU1024::add(const U1024& a,const U1024& b) const {
 U1024 r{}; std::uint64_t carry=0;
 for(std::size_t i=0;i<r.limb.size();++i){
  const auto s=a.limb[i]+b.limb[i]; const std::uint64_t c1=s<a.limb[i];
  const auto s2=s+carry; const std::uint64_t c2=s2<s;
  r.limb[i]=s2; carry=c1|c2;
 }
 return r;
}
U1024 CPU1024::bit_xor(const U1024& a,const U1024& b) const {
 U1024 r{}; for(std::size_t i=0;i<r.limb.size();++i) r.limb[i]=a.limb[i]^b.limb[i]; return r;
}
}