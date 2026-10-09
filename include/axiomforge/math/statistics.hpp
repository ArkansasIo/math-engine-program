#pragma once
#include <vector>
namespace axf::math {
double mean(const std::vector<double>& values);
double median(std::vector<double> values);
double variance(const std::vector<double>& values,bool sample=false);
double standard_deviation(const std::vector<double>& values,bool sample=false);
}
