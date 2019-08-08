#include "core/nodes/others/bracket.h"

#include <memory>

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

std::shared_ptr<Node> CloseBracket::ExtendTree(Node& open_bracket) {
  std::shared_ptr<Node> parent{open_bracket.parent_};
  parent->right_ = std::move(open_bracket->right_);
  parent->right_->parent_ = std::move(open_bracket.parent_);
  return parent;
}

}  // namespace nodes
}  // namespace calc
