#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NODE_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NODE_H_

#include <memory>

#include "core/expr.h"
#include "core/impl/nodes/priority.h"

namespace calc {
namespace impl {
namespace nodes {

class Node : public ::calc::Expression {
 public:
  Node(Precedence precedence) : priority(precedence) {}
  virtual ~Node();

  float GetValue() const;
  Node* AddNode(std::unique_ptr<Node>);
  
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
  const Priority priority;

 private:
  virtual bool IsValidParent(const Node&) const;
  virtual float ComputeValue() const;
  virtual Node* ExtendTree(Node*);
};

}  // namespace nodes
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NODE_H_
