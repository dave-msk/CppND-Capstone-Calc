#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_

#include <memory>
#include <utility>

#include "core/nodes/priority.h"

namespace calc {

class Node : public std::enable_shared_from_this<Node> {
 public:
  Node(Precedence precedence) : priority_(precedence) {}
  virtual ~Node() {}

  float GetValue() { return ComputeValue(); }
  std::shared_ptr<Node> AddNode(std::unique_ptr<Node>);
  std::shared_ptr<Node> GetParent() { return parent_; }

 protected:
  std::shared_ptr<Node> parent_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> right_;
  const Priority priority_; 
 
 private:
  virtual float ComputeValue();
  virtual bool IsValidParent(const Node&) const;
  virtual std::shared_ptr<Node> ExtendTree(Node& parent);
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_NODE_H_
