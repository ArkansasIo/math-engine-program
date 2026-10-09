#include "axiomforge/ui/menu.hpp"
namespace axf {
std::unique_ptr<Menu> make_main_menu(){auto m=std::make_unique<Menu>();m->title="AxiomForge";m->items={{"math","Mathematics","",{{"arithmetic","Arithmetic","math",{}},{"number-theory","Number Theory","math",{}},{"calculus","Calculus","math",{}}}},{"graph","Knowledge Graph","graph",{}},{"updates","Updates","update status",{}},{"about","About","about",{}}};return m;}
}
