#include "core/impl/nodes/misc.h"

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

OpenBracket::OpenBracket() : Node(Precedence::ONE) {}

bool OpenBracket::IsValidParent(const Node&) const { return true; }

CloseBracket::CloseBracket() : Node(Precedence::ONE) {}

bool CloseBracket::IsValidParent(const Node& node) const {
  return dynamic_cast<const OpenBracket*>(std::addressof(node)) != nullptr;
}

Node* CloseBracket::ExtendTree(Node* open_bracket) {
  Node* new_parent = open_bracket->parent;
  new_parent->right = open_bracket->right;
  open_bracket->right->parent = new_parent;

  open_bracket->parent = open_bracket->left = open_bracket->right = nullptr;
  delete open_bracket, this;
  return new_parent;
}

}  // namespace nodes
}  // namespace impl
}  // namespace calc
