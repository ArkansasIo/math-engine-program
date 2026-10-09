#include "axiomforge/math/vector3.hpp"
#include <cmath>
#include <stdexcept>
namespace axf::math {
Vector3 operator+(Vector3 a,Vector3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
Vector3 operator-(Vector3 a,Vector3 b){return{a.x-b.x,a.y-b.y,a.z-b.z};}
Vector3 operator*(Vector3 v,double s){return{v.x*s,v.y*s,v.z*s};}
double dot(Vector3 a,Vector3 b){return a.x*b.x+a.y*b.y+a.z*b.z;}
Vector3 cross(Vector3 a,Vector3 b){return{a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
double norm(Vector3 v){return std::sqrt(dot(v,v));}
Vector3 normalized(Vector3 v){double n=norm(v);if(n<=0||!std::isfinite(n))throw std::invalid_argument("cannot normalize zero or non-finite vector");return v*(1.0/n);}
}
