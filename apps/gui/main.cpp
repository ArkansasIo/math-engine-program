#include "axiomforge/ui/menu.hpp"
#include "axiomforge/ui/window.hpp"
#include <iostream>
int main(){auto menu=axf::make_main_menu();axf::WindowModel window({"AxiomForge Mathematics Platform",1280,800,true});std::cout<<window.spec().title<<" ["<<window.spec().width<<"x"<<window.spec().height<<"]\n";std::cout<<"GUI shell mock - native windowing is not implemented.\n"<<menu->title<<" menu:\n";for(const auto&i:menu->items)std::cout<<" - "<<i.label<<'\n';return 0;}
