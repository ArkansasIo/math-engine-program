#include "axiomforge/math/geometry.hpp"
#include <cmath>
#include <numbers>
#include <stdexcept>
namespace axf::math {
double distance(Point2 a,Point2 b){return std::hypot(a.x-b.x,a.y-b.y);}
double circle_area(double r){if(r<0||!std::isfinite(r))throw std::invalid_argument("radius must be finite and nonnegative");return std::numbers::pi*r*r;}
double triangle_area(Point2 a,Point2 b,Point2 c){return std::abs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0);}
double sphere_volume(double r){if(r<0||!std::isfinite(r))throw std::invalid_argument("radius must be finite and nonnegative");return (4.0/3.0)*std::numbers::pi*r*r*r;}
}
