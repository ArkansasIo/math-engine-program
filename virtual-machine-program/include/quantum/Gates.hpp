#pragma once
#include "QubitRegister.hpp"
namespace quantum { void hadamard(QubitRegister&,std::size_t); void pauli_x(QubitRegister&,std::size_t); void cnot(QubitRegister&,std::size_t,std::size_t); }