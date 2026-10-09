#include "axiomforge/terminal/terminal.hpp"
#include <iostream>
#include <utility>
namespace axf {
void Terminal::run(){std::string line;while(std::cout<<"> "&&std::getline(std::cin,line)){if(line=="quit"||line=="exit")break;std::cout<<handler_(line)<<'\n';}}
}
