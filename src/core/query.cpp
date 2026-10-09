#include "axiomforge/core/query.hpp"
#include "axiomforge/math/arithmetic.hpp"
#include "axiomforge/math/combinatorics.hpp"
#include "axiomforge/math/logic.hpp"
#include "axiomforge/math/number_theory.hpp"
#include "axiomforge/math/polynomial.hpp"
#include "axiomforge/math/statistics.hpp"
#include <sstream>
#include <vector>
namespace axf {
namespace {
bool parse_bool(const std::string&s,bool&v){if(s=="true"||s=="1"){v=true;return true;}if(s=="false"||s=="0"){v=false;return true;}return false;}
}
std::string QueryEngine::execute(const std::string& input)const{
 std::istringstream in(input);std::string group,command;in>>group>>command;
 if(input=="help")return "math add|subtract|multiply A B; math prime|classify|factorial N; math gcd|lcm A B; math choose|permute N R; math mean|median X...; math derivative|integral C0 C1...; logic not A|and|or|xor|implies|equivalent A B; graph children ID|path A B";
 if(group=="math"){
  if(command=="add"||command=="subtract"||command=="multiply"){Integer a{},b{};if(!(in>>a>>b))return "usage: math "+command+" A B";if(command=="add")return std::to_string(add(a,b));if(command=="subtract")return std::to_string(subtract(a,b));return std::to_string(multiply(a,b));}
  if(command=="prime"||command=="classify"||command=="factorial"){long long n{};if(!(in>>n))return "usage: math "+command+" N";if(command=="prime")return is_prime(n)?"true":"false";if(command=="classify")return classify(n);if(n<0||n>1000)return "factorial requires 0 <= N <= 1000";try{return std::to_string(math::factorial(static_cast<unsigned>(n)));}catch(const std::exception&e){return e.what();}}
  if(command=="gcd"||command=="lcm"){Integer a{},b{};if(!(in>>a>>b))return "usage: math "+command+" A B";return std::to_string(command=="gcd"?gcd(a,b):lcm(a,b));}
  if(command=="choose"||command=="permute"){unsigned n{},r{};if(!(in>>n>>r))return "usage: math "+command+" N R";try{return std::to_string(command=="choose"?math::combinations(n,r):math::permutations(n,r));}catch(const std::exception&e){return e.what();}}
  if(command=="mean"||command=="median"){std::vector<double>v;double x;while(in>>x)v.push_back(x);try{return std::to_string(command=="mean"?math::mean(v):math::median(v));}catch(const std::exception&e){return e.what();}}
  if(command=="derivative"||command=="integral"){std::vector<double>c;double x;while(in>>x)c.push_back(x);if(c.empty())return "usage: math "+command+" C0 C1 ... (coefficients in ascending power order)";math::Polynomial p(c);return (command=="derivative"?p.derivative():p.integral()).to_string();}
 }
 if(group=="logic"){bool a{},b{};std::string sa,sb;in>>sa;if(command=="not"){if(!parse_bool(sa,a))return "logic values must be true, false, 1, or 0";return math::logical_not(a)?"true":"false";}if(!(in>>sb)||!parse_bool(sa,a)||!parse_bool(sb,b))return "usage: logic and|or|xor|implies|equivalent A B";bool r=false;if(command=="and")r=math::logical_and(a,b);else if(command=="or")r=math::logical_or(a,b);else if(command=="xor")r=math::logical_xor(a,b);else if(command=="implies")r=math::implies(a,b);else if(command=="equivalent")r=math::equivalent(a,b);else return "unknown logic operator";return r?"true":"false";}
 if(group=="graph"&&command=="children"){std::string id;if(!(in>>id))return "usage: graph children NODE";std::string out;for(const auto&n:graph_.children(id))out+=n.id+"\n";return out.empty()?"(none)":out;}
 if(group=="graph"&&command=="path"){std::string a,b;if(!(in>>a>>b))return "usage: graph path FROM TO";auto p=graph_.path(a,b);if(p.empty())return "no path";std::string out;for(std::size_t i=0;i<p.size();++i){if(i)out+=" -> ";out+=p[i];}return out;}
 return "Unknown command. Type help.";
}
}
