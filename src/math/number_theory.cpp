#include "axiomforge/math/number_theory.hpp"
#include <cstdlib>
namespace axf {
bool is_prime(std::int64_t n){if(n<2)return false;if(n%2==0)return n==2;for(std::int64_t d=3;d<=n/d;d+=2)if(n%d==0)return false;return true;}
std::int64_t gcd(std::int64_t a,std::int64_t b){a=std::llabs(a);b=std::llabs(b);while(b){auto r=a%b;a=b;b=r;}return a;}
std::int64_t lcm(std::int64_t a,std::int64_t b){if(a==0||b==0)return 0;return std::llabs((a/gcd(a,b))*b);}
std::vector<std::int64_t> prime_factors(std::int64_t n){std::vector<std::int64_t>r;n=std::llabs(n);while(n>1&&n%2==0){r.push_back(2);n/=2;}for(std::int64_t p=3;p<=n/p;p+=2)while(n%p==0){r.push_back(p);n/=p;}if(n>1)r.push_back(n);return r;}
}
