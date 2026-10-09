#include "axiomforge/math/combinatorics.hpp"
#include <limits>
#include <numeric>
#include <stdexcept>
namespace axf::math {
namespace {std::uint64_t checked_mul(std::uint64_t a,std::uint64_t b){if(b&&a>std::numeric_limits<std::uint64_t>::max()/b)throw std::overflow_error("combinatorics result exceeds uint64");return a*b;}}
std::uint64_t factorial(unsigned n){std::uint64_t r=1;for(unsigned i=2;i<=n;++i)r=checked_mul(r,i);return r;}
std::uint64_t permutations(unsigned n,unsigned r){if(r>n)throw std::invalid_argument("r must not exceed n");std::uint64_t out=1;for(unsigned i=0;i<r;++i)out=checked_mul(out,n-i);return out;}
std::uint64_t combinations(unsigned n,unsigned r){if(r>n)throw std::invalid_argument("r must not exceed n");r=r<n-r?r:n-r;std::uint64_t out=1;for(unsigned i=1;i<=r;++i){std::uint64_t numerator=n-r+i;std::uint64_t divisor=i;auto g=std::gcd(numerator,divisor);numerator/=g;divisor/=g;auto g2=std::gcd(out,divisor);out/=g2;divisor/=g2;if(divisor!=1)throw std::logic_error("combination reduction invariant failed");out=checked_mul(out,numerator);}return out;}
}
