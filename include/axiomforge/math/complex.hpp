#pragma once
#include <complex>
namespace axf::math {
using Complex=std::complex<double>;
inline double complex_magnitude(Complex z){return std::abs(z);}
inline double complex_phase(Complex z){return std::arg(z);}
inline Complex complex_conjugate(Complex z){return std::conj(z);}
inline Complex complex_exp(Complex z){return std::exp(z);}
inline Complex complex_log(Complex z){return std::log(z);}
}
