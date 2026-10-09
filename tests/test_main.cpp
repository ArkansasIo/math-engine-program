#include "axiomforge/core/graph.hpp"
#include "axiomforge/core/query.hpp"
#include "axiomforge/math/arithmetic.hpp"
#include "axiomforge/math/number_theory.hpp"
#include "axiomforge/math/polynomial.hpp"
#include "axiomforge/math/matrix.hpp"
#include "axiomforge/math/statistics.hpp"
#include "axiomforge/math/combinatorics.hpp"
#include "axiomforge/math/logic.hpp"
#include "axiomforge/math/sets.hpp"
#include "axiomforge/math/vector3.hpp"
#include "axiomforge/math/geometry.hpp"
#include "axiomforge/math/numerical.hpp"
#include "axiomforge/math/probability.hpp"
#include "axiomforge/math/units.hpp"
#include "axiomforge/math/complex.hpp"
#include <set>
#include <cmath>
#include <cassert>
int main(){assert(axf::add(2,3)==5);assert(axf::multiply(-4,5)==-20);assert(axf::classify(-12)=="negative integer, even");assert(axf::is_prime(97));assert(!axf::is_prime(1));assert(axf::gcd(84,30)==6);auto g=axf::make_default_graph();assert(g.find("calculus"));assert(!g.children("calculus").empty());assert(g.path("calculus","integrals").size()==2);axf::QueryEngine qe(g);assert(qe.execute("math choose 5 2")=="10");assert(qe.execute("logic implies false false")=="true");assert(qe.execute("math derivative 1 2 1")=="2x + 2");
 axf::math::Polynomial p({1.0,2.0,1.0});assert(p.evaluate(2.0)==9.0);assert(p.derivative().evaluate(2.0)==6.0);assert(std::abs(p.integral().evaluate(2.0)-(8.0/3.0+4.0+2.0))<1e-9);
 axf::math::Matrix m({{1,2},{3,4}});assert(m.determinant()==-2.0);auto mt=m.transpose();assert(mt.at(0,1)==3.0);
 assert(axf::math::mean({1,2,3,4})==2.5);assert(axf::math::median({9,1,5})==5.0);
 assert(axf::math::factorial(5)==120);assert(axf::math::permutations(5,2)==20);assert(axf::math::combinations(5,2)==10);
 assert(axf::math::implies(false,false));assert(!axf::math::implies(true,false));assert(axf::math::truth_table(axf::math::LogicalOperator::And).size()==4);
 assert(axf::math::set_union(std::set<int>{1,2},std::set<int>{2,3}).size()==3);
 axf::math::Vector3 v{1,0,0},w{0,1,0};assert(axf::math::dot(v,w)==0);assert(axf::math::cross(v,w).z==1);
 assert(std::abs(axf::math::circle_area(1)-3.141592653589793)<1e-12);assert(axf::math::distance({0,0},{3,4})==5);
 assert(std::abs(axf::math::derivative_numeric([](double x){return x*x;},3.0)-6.0)<1e-5);
 assert(std::abs(axf::math::integrate_simpson([](double x){return x*x;},0,1,100)-1.0/3.0)<1e-9);
 assert(std::abs(axf::math::root_bisection([](double x){return x*x-2;},1,2)-std::sqrt(2.0))<1e-8);
 assert(std::abs(axf::math::normal_cdf(0)-0.5)<1e-12);assert(std::abs(axf::math::binomial_pmf(2,1,0.5)-0.5)<1e-12);
 assert(std::abs(axf::math::convert_unit(1,axf::math::Unit::Kilometer,axf::math::Unit::Meter)-1000)<1e-12);
 assert(axf::math::complex_magnitude({3,4})==5);
 return 0;}
