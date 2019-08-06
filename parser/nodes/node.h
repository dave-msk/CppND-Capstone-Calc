#ifndef CPPND_CAPSTONE_CALC_PARSER_NODES_NODE_H_
#define CPPND_CAPSTONE_CALC_PARSER_NODES_NODE_H_

#include <memory>
#include <utility>

#include "parser/nodes/priority.h"

namespace calc {

class Node : public std::enable_shared_from_this<Node> {
 public:
  Node(Precedence precedence) : priority_(precedence) {}
  virtual ~Node() {}

  float GetValue() { return ComputeValue(); }
  std::shared_ptr<Node> AddNode(std::unique_ptr<Node>);
  std::shared_ptr<Node> GetParent() { return parent_; }
 
 private:
  using std::enable_shared_from_this<Node>::shared_from_this;
  
  virtual float ComputeValue();
  virtual bool IsValidParent(const Node& node) const;
  virtual std::shared_ptr<Node> ExtendTree(Node& parent);

  const Priority priority_;
  
  std::shared_ptr<Node> parent_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> right_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_PARSER_NODES_NODE_H_
