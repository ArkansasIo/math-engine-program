#include "axiomforge/math/equations.hpp"
#include <cmath>
#include <stdexcept>
namespace axf::math {
std::optional<double> solve_linear(double a,double b){if(!std::isfinite(a)||!std::isfinite(b))throw std::invalid_argument("coefficients must be finite");if(std::abs(a)<1e-14)return std::nullopt;return -b/a;}
std::vector<std::complex<double>> solve_quadratic(double a,double b,double c){if(!std::isfinite(a)||!std::isfinite(b)||!std::isfinite(c))throw std::invalid_argument("coefficients must be finite");if(std::abs(a)<1e-14){auto r=solve_linear(b,c);if(!r)return{};return{{*r,0.0}};}double d=b*b-4*a*c;if(d>=0){double root=std::sqrt(d);return{{(-b+root)/(2*a),0.0},{(-b-root)/(2*a),0.0}};}double real=-b/(2*a),imag=std::sqrt(-d)/(2*std::abs(a));return{{real,imag},{real,-imag}};}
}
