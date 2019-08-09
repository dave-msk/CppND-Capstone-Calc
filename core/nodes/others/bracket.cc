#include "core/nodes/others/bracket.h"

#include "core/nodes/node.h"
#include "core/nodes/priority.h"

namespace calc {
namespace nodes {

OpenBracket::OpenBracket() : Node(Precedence::ONE) {}

bool OpenBracket::IsValidParent(const Node&) const { return true; }

CloseBracket::CloseBracket() : Node(Precedence::ONE) {}

bool CloseBracket::IsValidParent(const Node& node) const {
  return dynamic_cast<OpenBracket*>(std::addressof(node)) != nullptr;
}

Node* CloseBracket::ExtendTree(Node* open_bracket) {
  Node* parent = open_bracket->parent_;
  parent->right_ = open_bracket->right_;
  parent->right_->parent_ = parent;

  open_bracket->parent_ = nullptr;
  open_bracket->left_ = nullptr;
  open_bracket->right_ = nullptr;
  parent_ = nullptr;
  left_ = nullptr;
  right_ = nullptr;

  delete open_bracket, this;
  return parent;
}

}  // namespace nodes
}  // namespace calc
