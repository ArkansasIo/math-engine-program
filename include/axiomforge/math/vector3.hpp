#pragma once
namespace axf::math {
struct Vector3 { double x{},y{},z{}; };
Vector3 operator+(Vector3 a,Vector3 b);
Vector3 operator-(Vector3 a,Vector3 b);
Vector3 operator*(Vector3 v,double scalar);
double dot(Vector3 a,Vector3 b);
Vector3 cross(Vector3 a,Vector3 b);
double norm(Vector3 v);
Vector3 normalized(Vector3 v);
}
