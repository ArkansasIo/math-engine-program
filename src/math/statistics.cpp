#include "axiomforge/math/statistics.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <stdexcept>
namespace axf::math {
double mean(const std::vector<double>&v){if(v.empty())throw std::invalid_argument("mean requires at least one value");return std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size());}
double median(std::vector<double>v){if(v.empty())throw std::invalid_argument("median requires at least one value");std::sort(v.begin(),v.end());auto n=v.size();return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;}
double variance(const std::vector<double>&v,bool sample){if(v.empty()||(sample&&v.size()<2))throw std::invalid_argument("insufficient values for variance");double m=mean(v),sum=0;for(double x:v){double d=x-m;sum+=d*d;}return sum/static_cast<double>(v.size()-(sample?1:0));}
double standard_deviation(const std::vector<double>&v,bool sample){return std::sqrt(variance(v,sample));}
}
