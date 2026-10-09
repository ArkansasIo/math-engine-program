#include "axiomforge/math/probability.hpp"
#include "axiomforge/math/combinatorics.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>
namespace axf::math {
double binomial_pmf(unsigned n,unsigned k,double p){if(k>n||p<0||p>1||!std::isfinite(p))throw std::invalid_argument("binomial requires k<=n and p in [0,1]");if(p==0)return k==0?1:0;if(p==1)return k==n?1:0;long double choose=static_cast<long double>(combinations(n,k));return static_cast<double>(choose*std::pow(p,static_cast<int>(k))*std::pow(1-p,static_cast<int>(n-k)));}
double normal_pdf(double x,double m,double s){if(!(s>0)||!std::isfinite(s))throw std::invalid_argument("standard deviation must be positive and finite");constexpr double invSqrt2Pi=0.3989422804014327;double z=(x-m)/s;return invSqrt2Pi/s*std::exp(-0.5*z*z);}
double normal_cdf(double x,double m,double s){if(!(s>0)||!std::isfinite(s))throw std::invalid_argument("standard deviation must be positive and finite");return 0.5*std::erfc(-(x-m)/(s*std::sqrt(2.0)));}
double uniform_pdf(double x,double a,double b){if(!(a<b)||!std::isfinite(a)||!std::isfinite(b))throw std::invalid_argument("uniform bounds must be finite with lower < upper");return x<a||x>b?0.0:1.0/(b-a);}
}
