#include "core/nodes/node.h"

#include <memory>
#include <utility>

namespace calc {

std::shared_ptr<Node> Node::AddNode(std::unique_ptr<Node> node) {
  std::shared_ptr<Node> shared_node{std::move(node)};
  Node *raw_parent = parent_.get();
  while (!shared_node->IsValidParent(*raw_parent)) {
    raw_parent = raw_parent->parent_.get();
  }
  return shared_node->ExtendTree(*raw_parent);
}

bool Node::IsValidParent(const Node& node) const {
  return node.prioriy_ < prioriy_;
}

float Node::ComputeValue() {
  return 0f;
}

std::shared_ptr<Node> Node::ExtendTree(Node& parent) {
  parent_ = parent.shared_from_this();
  if (parent.right_ != nullptr && left_ == nullptr) {
    left_ = std::move(parent.right_);
    parent.right_ = shared_from_this();
    left_->parent_ = shared_from_this();
  }
  return shared_from_this();
}

}  // namespace calc
