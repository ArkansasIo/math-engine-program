#include "axiomforge/math/optimization.hpp"
#include <cmath>
#include <stdexcept>
namespace axf::math {
Minimum golden_section_minimize(const std::function<double(double)>&f,double a,double b,double tol,std::size_t max){if(!(a<b)||!(tol>0)||!std::isfinite(a)||!std::isfinite(b)||!std::isfinite(tol)||max==0)throw std::invalid_argument("invalid optimization bounds or tolerance");constexpr double ratio=0.6180339887498948482;double c=b-ratio*(b-a),d=a+ratio*(b-a),fc=f(c),fd=f(d);std::size_t iterations=0;for(;iterations<max&&std::abs(b-a)>tol;++iterations){if(!std::isfinite(fc)||!std::isfinite(fd))throw std::runtime_error("objective returned non-finite value");if(fc<fd){b=d;d=c;fd=fc;c=b-ratio*(b-a);fc=f(c);}else{a=c;c=d;fc=fd;d=a+ratio*(b-a);fd=f(d);}}double x=(a+b)/2;return{x,f(x),iterations};}
}
