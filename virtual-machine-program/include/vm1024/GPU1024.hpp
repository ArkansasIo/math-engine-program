#pragma once
#include "Types.hpp"
namespace vm1024 {
class GPU1024 {
public:
  V1024 add(const V1024&,const V1024&) const;
  U1024 dot(const V1024&,const V1024&) const;
};
}
