#pragma once
#include <string>
#include <vector>
namespace axf::math {
enum class LogicalOperator { Not, And, Or, Xor, Implies, Equivalent };
bool logical_not(bool a);
bool logical_and(bool a,bool b);
bool logical_or(bool a,bool b);
bool logical_xor(bool a,bool b);
bool implies(bool a,bool b);
bool equivalent(bool a,bool b);
struct TruthRow { bool a; bool b; bool result; };
std::vector<TruthRow> truth_table(LogicalOperator op);
std::string to_string(LogicalOperator op);
}
