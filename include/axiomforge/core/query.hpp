#pragma once
#include "graph.hpp"
#include <string>
namespace axf {
class QueryEngine {
public:
 explicit QueryEngine(const KnowledgeGraph& graph):graph_(graph){}
 std::string execute(const std::string& input) const;
private:
 const KnowledgeGraph& graph_;
};
}
