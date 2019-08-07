#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OTHERS_REGISTRY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OTHERS_REGISTRY_H_

#include <memory>

#include "core/nodes/node.h"

namespace calc {

enum class MiscType {
  OPEN_BRACKET,
  CLOSE_BRACKET
};

std::unique_ptr<Node> CreateNode(MiscType);

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OTHERS_REGISTRY_H_
