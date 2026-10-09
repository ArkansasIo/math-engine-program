#include "axiomforge/math/interpolation.hpp"
#include <cmath>
#include <stdexcept>
namespace axf::math {
double lagrange_interpolate(const std::vector<double>&x,const std::vector<double>&y,double target){if(x.empty()||x.size()!=y.size())throw std::invalid_argument("interpolation vectors must be nonempty and equally sized");double result=0;for(std::size_t i=0;i<x.size();++i){double term=y[i];for(std::size_t j=0;j<x.size();++j){if(i==j)continue;double d=x[i]-x[j];if(std::abs(d)<1e-14)throw std::invalid_argument("interpolation x coordinates must be distinct");term*=((target-x[j])/d);}result+=term;}return result;}
}
