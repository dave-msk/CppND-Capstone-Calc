#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_

#include <memory>

#include "core/nodes/priority.h"

namespace calc {

namespace parser {
  class Parser;
}  // namespace parser

namespace nodes {

class Node {
  friend class ::calc::parser::Grammar;

 public:
  Node(Precedence precedence) : priority_(precedence) {}
  virtual ~Node();

  float GetValue() { return ComputeValue(); }

 protected:
  Node* parent_ = nullptr;
  Node* left_ = nullptr;
  Node* right_ = nullptr;
  const Priority priority_;
 
 private:
  Node* AddNode(std::unique_ptr<Node>);

  virtual float ComputeValue();
  virtual bool IsValidParent(const Node&) const;
  virtual Node* ExtendTree(Node*);
};

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_
