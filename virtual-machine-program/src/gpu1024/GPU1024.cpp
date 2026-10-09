#include "vm1024/GPU1024.hpp"
namespace vm1024 {
V1024 GPU1024::add(const V1024&a,const V1024&b)const{V1024 r;for(int i=0;i<16;i++)r.lane[i]=a.lane[i]+b.lane[i];return r;}
U1024 GPU1024::dot(const V1024&a,const V1024&b)const{U1024 r;for(int i=0;i<16;i++)r.limb[0]+=a.lane[i]*b.lane[i];return r;}
}
