#pragma once
#include <complex>
#include <vector>
namespace quantum {
class QubitRegister {
  std::vector<std::complex<double>> state_;
public:
  explicit QubitRegister(std::size_t qubits);
  std::size_t qubits() const noexcept;
  const auto& state() const noexcept { return state_; }
  auto& state_mutable() noexcept { return state_; }
  void normalize();
};
}