#pragma once
#include <cstddef>
#include <functional>
namespace axf::math {
double derivative_numeric(const std::function<double(double)>&f,double x,double h=1e-5);
double integrate_simpson(const std::function<double(double)>&f,double a,double b,std::size_t intervals=1000);
double root_bisection(const std::function<double(double)>&f,double a,double b,double tolerance=1e-10,std::size_t max_iterations=1000);
}
