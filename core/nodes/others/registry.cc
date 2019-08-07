#include "core/nodes/others/registry.h"

#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/others/bracket.h"

namespace calc {

std::unique<Node> CreateNode(MiscType type) {
  switch (type) {
    case MiscType::OPEN_BRACKET:
      return std::unique_ptr<Node>(new OpenBracket());
    case MiscType::CLOSE_BRACKET:
      return std::unique_ptr<Node>(new CloseBracket());
  }
}

}  // namespace calc
