#pragma once
namespace axf::math {
double binomial_pmf(unsigned n,unsigned k,double p);
double normal_pdf(double x,double mean=0.0,double standard_deviation=1.0);
double normal_cdf(double x,double mean=0.0,double standard_deviation=1.0);
double uniform_pdf(double x,double lower,double upper);
}
