#include "axiomforge/math/numerical.hpp"
#include <cmath>
#include <stdexcept>
namespace axf::math {
double derivative_numeric(const std::function<double(double)>&f,double x,double h){if(!(h>0)||!std::isfinite(h))throw std::invalid_argument("step size must be positive and finite");return(f(x+h)-f(x-h))/(2*h);}
double integrate_simpson(const std::function<double(double)>&f,double a,double b,std::size_t n){if(n==0||n%2!=0)throw std::invalid_argument("Simpson interval count must be positive and even");double h=(b-a)/static_cast<double>(n),sum=f(a)+f(b);for(std::size_t i=1;i<n;++i)sum+=(i%2?4.0:2.0)*f(a+h*static_cast<double>(i));return sum*h/3.0;}
double root_bisection(const std::function<double(double)>&f,double a,double b,double tol,std::size_t max){if(!(tol>0)||!std::isfinite(tol)||max==0)throw std::invalid_argument("invalid bisection tolerance or iteration count");double fa=f(a),fb=f(b);if(!std::isfinite(fa)||!std::isfinite(fb)||fa*fb>0)throw std::invalid_argument("root must be bracketed by finite endpoint values");if(fa==0)return a;if(fb==0)return b;for(std::size_t i=0;i<max;++i){double m=a+(b-a)/2,fm=f(m);if(!std::isfinite(fm))throw std::runtime_error("function returned a non-finite value");if(std::abs(fm)<=tol||std::abs(b-a)<=tol)return m;if((fa<0&&fm>0)||(fa>0&&fm<0)){b=m;fb=fm;}else{a=m;fa=fm;}}return a+(b-a)/2;}
}
