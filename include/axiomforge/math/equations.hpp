#pragma once
#include <complex>
#include <optional>
#include <vector>
namespace axf::math {
std::optional<double> solve_linear(double a,double b);
std::vector<std::complex<double>> solve_quadratic(double a,double b,double c);
}
