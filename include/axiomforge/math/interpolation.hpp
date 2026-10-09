#pragma once
#include <vector>
namespace axf::math {
double lagrange_interpolate(const std::vector<double>&x,const std::vector<double>&y,double target);
}
