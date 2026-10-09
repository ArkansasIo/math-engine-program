#include "quantum/Gates.hpp"
#include "quantum/Measurement.hpp"
#include <cassert>
#include <cmath>
int main(){quantum::QubitRegister r(2);quantum::hadamard(r,0);quantum::cnot(r,0,1);assert(std::abs(quantum::probability_zero(r,0)-0.5)<1e-12);assert(std::abs(quantum::probability_zero(r,1)-0.5)<1e-12);}