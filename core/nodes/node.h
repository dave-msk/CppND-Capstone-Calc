#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_

#include <memory>
#include <utility>

#include "core/nodes/priority.h"

namespace calc {
namespace nodes {

class Node : public std::enable_shared_from_this<Node> {
 public:
  

  Node(Precedence precedence) : priority_(precedence) {}
  virtual ~Node() {}

  float GetValue() { return ComputeValue(); }

 protected:
  Node* parent_;
  Node* left_;
  Node* right_;
  const Priority priority_;
 
 private:
  Node* AddNode(std::unique_ptr<Node>);

  virtual float ComputeValue();
  virtual bool IsValidParent(const Node&) const;
  virtual std::shared_ptr<Node> ExtendTree(Node& parent);
};

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_
