#pragma once
#include <string>
namespace axf {
enum class NodeType { Root, Trunk, Branch, SubBranch, Twig, Leaf, Concept, Formula, Function, Theorem };
struct Node { std::string id; std::string name; NodeType type{NodeType::Concept}; std::string symbol; std::string definition; };
struct Edge { std::string from, relation, to; };
}
