#pragma once
namespace axf::math {
struct Point2 { double x{},y{}; };
double distance(Point2 a,Point2 b);
double circle_area(double radius);
double triangle_area(Point2 a,Point2 b,Point2 c);
double sphere_volume(double radius);
}
