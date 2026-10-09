#pragma once
#include "QubitRegister.hpp"
namespace quantum {
class QuantumCircuit {
  QubitRegister reg_;
public:
  explicit QuantumCircuit(std::size_t qubits):reg_(qubits){}
  QubitRegister& register_state(){return reg_;}
};
}
