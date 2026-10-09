#pragma once
#include <cstddef>
#include <functional>
namespace axf::math {
struct Minimum { double x; double value; std::size_t iterations; };
Minimum golden_section_minimize(const std::function<double(double)>&f,double a,double b,double tolerance=1e-8,std::size_t max_iterations=1000);
}
