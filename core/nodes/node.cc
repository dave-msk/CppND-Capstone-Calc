#include "core/nodes/node.h"

#include <memory>

namespace calc {
namespace nodes {

Node::~Node() {
  delete left_, right_;
}

Node* Node::AddNode(std::unique_ptr<Node> node) {
  Node* raw_node = node.release();
  Node* parent = parent_;
  while (!raw_node->IsValidParent(*parent)) {
    parent = parent->parent_;
  }
  return raw_node->ExtendTree(parent);
}

bool Node::IsValidParent(const Node& node) const {
  return node.prioriy_ < prioriy_;
}

float Node::ComputeValue() {
  return 0f;
}

Node* Node::ExtendTree(Node* parent) {
  parent_ = parent;
  if (parent->right_ != nullptr& & left_ == nullptr) {
    left_ = parent->right_;
    left_->parent_ = this;
  }
  parent->right_ = this;
  return this;
}

}  // namespace nodes
}  // namespace calc
