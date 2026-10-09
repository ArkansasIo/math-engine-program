#include "vm1024/CPU1024.hpp"
#include "quantum/QubitRegister.hpp"
#include <cassert>
int main(){vm1024::CPU1024 c;vm1024::U1024 a{},b{};a.limb[0]=7;b.limb[0]=5;assert(c.add(a,b).limb[0]==12);quantum::QubitRegister q(3);assert(q.qubits()==3);return 0;}
