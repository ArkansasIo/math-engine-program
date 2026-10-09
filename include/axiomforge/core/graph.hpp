#pragma once
#include "node.hpp"
#include <string>
#include <unordered_map>
#include <vector>
namespace axf {
class KnowledgeGraph {
public:
 bool add_node(Node node);
 bool add_edge(Edge edge);
 const Node* find(const std::string& id) const;
 std::vector<Node> children(const std::string& id) const;
 std::vector<std::string> path(const std::string& from,const std::string& to) const;
 std::vector<Node> all_nodes() const;
private:
 std::unordered_map<std::string,Node> nodes_;
 std::vector<Edge> edges_;
};
KnowledgeGraph make_default_graph();
}
