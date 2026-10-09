#include "vm1024/CPU1024.hpp"
namespace vm1024 {
U1024 CPU1024::add(const U1024&a,const U1024&b){
 U1024 r{}; std::uint64_t carry=0;
 for(std::size_t i=0;i<r.size();++i){
  std::uint64_t s=a[i]+b[i]; std::uint64_t c1=(s<a[i])?1:0;
  std::uint64_t s2=s+carry; std::uint64_t c2=(s2<s)?1:0;
  r[i]=s2; carry=c1|c2;
 } return r;
}
U1024 CPU1024::bit_xor(const U1024&a,const U1024&b){U1024 r{};for(std::size_t i=0;i<r.size();++i)r[i]=a[i]^b[i];return r;}
}