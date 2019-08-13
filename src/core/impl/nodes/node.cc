#include "core/impl/nodes/node.h"

#include <memory>

namespace calc {
namespace impl {
namespace nodes {

Node::~Node() {
  delete left, right;
}

float Node::GetValue() const {
  return ComputeValue();
}

Node* Node::AddNode(std::unique_ptr<Node> node) {
  Node* raw_node = node.release();
  Node* new_parent = this;

  while (!raw_node->IsValidParent(*new_parent)) {
    new_parent = new_parent->parent;
  }
  return raw_node->ExtendTree(new_parent);
}

bool Node::IsValidParent(const Node& node) const {
  return node.priority < priority;
}

float Node::ComputeValue() const {
  return 0.0f;
}

Node* Node::ExtendTree(Node* new_parent) {
  parent = new_parent;
  if (parent->right != nullptr && left == nullptr) {
    left = parent->right;
    left->parent = this;
  }
  parent->right = this;
  return this;
}

}  // namespace nodes
}  // namespace impl
}  // namespace calc
