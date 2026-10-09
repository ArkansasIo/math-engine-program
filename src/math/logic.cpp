#include "axiomforge/math/logic.hpp"
namespace axf::math {
bool logical_not(bool a){return !a;}bool logical_and(bool a,bool b){return a&&b;}bool logical_or(bool a,bool b){return a||b;}bool logical_xor(bool a,bool b){return a!=b;}bool implies(bool a,bool b){return !a||b;}bool equivalent(bool a,bool b){return a==b;}
std::vector<TruthRow> truth_table(LogicalOperator op){std::vector<TruthRow>r;for(bool a:{false,true})for(bool b:{false,true}){bool v=false;switch(op){case LogicalOperator::Not:v=!a;break;case LogicalOperator::And:v=a&&b;break;case LogicalOperator::Or:v=a||b;break;case LogicalOperator::Xor:v=a!=b;break;case LogicalOperator::Implies:v=!a||b;break;case LogicalOperator::Equivalent:v=a==b;break;}r.push_back({a,b,v});}return r;}
std::string to_string(LogicalOperator op){switch(op){case LogicalOperator::Not:return "NOT";case LogicalOperator::And:return "AND";case LogicalOperator::Or:return "OR";case LogicalOperator::Xor:return "XOR";case LogicalOperator::Implies:return "IMPLIES";case LogicalOperator::Equivalent:return "EQUIVALENT";}return "UNKNOWN";}
}
