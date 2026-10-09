#include "quantum/QubitRegister.hpp"
#include <cmath>
namespace quantum {
QubitRegister::QubitRegister(std::size_t q):state_(std::size_t(1)<<q),std::complex<double>{0,0}{state_[0]=1.0;}
std::size_t QubitRegister::qubits()const noexcept{std::size_t q=0,n=state_.size();while(n>1){n>>=1;++q;}return q;}
void QubitRegister::normalize(){double s=0;for(auto z:state_)s+=std::norm(z);if(s>0){auto f=1.0/std::sqrt(s);for(auto&z:state_)z*=f;}}
}
