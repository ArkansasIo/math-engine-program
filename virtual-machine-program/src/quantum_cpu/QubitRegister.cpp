#include "quantum/QubitRegister.hpp"
#include <cmath>
#include <stdexcept>
#include <limits>
namespace quantum {
QubitRegister::QubitRegister(std::size_t q) {
 if(q>=std::numeric_limits<std::size_t>::digits || q>24) throw std::invalid_argument("qubit count exceeds safe state-vector limit");
 state_.assign(std::size_t{1}<<q, std::complex<double>{0.0,0.0});
 state_[0]=1.0;
}
std::size_t QubitRegister::qubits() const noexcept {
 std::size_t q=0,n=state_.size(); while(n>1){n>>=1;++q;} return q;
}
void QubitRegister::normalize() {
 double sum=0.0; for(const auto z:state_) sum+=std::norm(z);
 if(sum<=0.0) throw std::runtime_error("cannot normalize zero quantum state");
 const auto scale=1.0/std::sqrt(sum); for(auto& z:state_) z*=scale;
}
}