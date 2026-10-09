#include "axiomforge/core/graph.hpp"
#include "axiomforge/math/arithmetic.hpp"
#include "axiomforge/math/number_theory.hpp"
#include <cassert>
int main(){assert(axf::add(2,3)==5);assert(axf::multiply(-4,5)==-20);assert(axf::classify(-12)=="negative integer, even");assert(axf::is_prime(97));assert(!axf::is_prime(1));assert(axf::gcd(84,30)==6);auto g=axf::make_default_graph();assert(g.find("calculus"));assert(!g.children("calculus").empty());assert(g.path("calculus","integrals").size()==2);return 0;}
