#include "vm1024/Memory.hpp"
#include <stdexcept>
namespace vm1024 {
Memory::Memory(std::size_t n):data_(n){}
std::uint8_t Memory::read8(Address a)const{if(a>=data_.size())throw std::out_of_range("VM memory read");return data_[a];}
void Memory::write8(Address a,std::uint8_t v){if(a>=data_.size())throw std::out_of_range("VM memory write");data_[a]=v;}
}
