#include "vm1024/CPU1024.hpp"
#include "quantum/QubitRegister.hpp"
#include <iostream>
int main(){vm1024::CPU1024 cpu; vm1024::U1024 a{},b{};a.limb[0]=40;b.limb[0]=2;auto r=cpu.add(a,b);quantum::QubitRegister q(2);std::cout<<"V1024 demo: "<<r.limb[0]<<"\nQubits: "<<q.qubits()<<"\n";return 0;}
