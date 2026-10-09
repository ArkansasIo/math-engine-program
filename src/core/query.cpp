#include "axiomforge/core/query.hpp"
#include "axiomforge/math/arithmetic.hpp"
#include "axiomforge/math/number_theory.hpp"
#include <sstream>
namespace axf {
std::string QueryEngine::execute(const std::string& input)const{
 std::istringstream in(input);std::string group,command;in>>group>>command;
 if(input=="help")return "math add A B | math prime N | math classify N | math gcd A B | graph children ID | graph path A B";
 if(group=="math"){
  if(command=="add"){Integer a{},b{};if(!(in>>a>>b))return "usage: math add A B";return std::to_string(add(a,b));}
  if(command=="prime"){Integer n{};if(!(in>>n))return "usage: math prime N";return is_prime(n)?"true":"false";}
  if(command=="classify"){Integer n{};if(!(in>>n))return "usage: math classify N";return classify(n);}
  if(command=="gcd"){Integer a{},b{};if(!(in>>a>>b))return "usage: math gcd A B";return std::to_string(gcd(a,b));}
 }
 if(group=="graph"&&command=="children"){std::string id;if(!(in>>id))return "usage: graph children NODE";std::string out;for(const auto&n:graph_.children(id))out+=n.id+"\n";return out.empty()?"(none)":out;}
 if(group=="graph"&&command=="path"){std::string a,b;if(!(in>>a>>b))return "usage: graph path FROM TO";auto p=graph_.path(a,b);if(p.empty())return "no path";std::string out;for(std::size_t i=0;i<p.size();++i){if(i)out+=" -> ";out+=p[i];}return out;}
 return "Unknown command. Type help.";
}
}
