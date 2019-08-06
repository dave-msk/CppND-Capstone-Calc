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

  std::shared_ptr<Node> AddNode(std::shared_ptr<Node> node); {
    Node *parent = parent_.get();
    while (!node->IsValidParent(*parent)) {
      parent = parent->parent_.get();
    }
    return node->ExtendTree(*parent);
  }

  float GetValue() { return ComputeValue(); }
  std::shared_ptr<Node> GetParent() const { return parent_; }
 
 private:
  virtual float ComputeValue() { return 0f; }
  
  virtual bool IsValidParent(const Node& node) const {
    return node.priority_ < priority_;
  };

  virtual std::shared_ptr<Node> ExtendTree(Node& parent) {
    parent_ = parent.shared_from_this();
    if (parent.right_ != nullptr && left_ == nullptr) {
      left_ = std::move(parent.right_);
      parent.right_ = shared_from_this();
      left_->parent_ = shared_from_this();
    }
  };

  const Priority priority_;
  
  std::shared_ptr<Node> parent_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> right_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_PARSER_NODES_NODE_H_
