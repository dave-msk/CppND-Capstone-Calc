#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_REGISTRY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_REGISTRY_H_

#include <memory>

#include "core/nodes/node.h"

namespace calc {

enum class BinaryOpType {
  ADD,
  MINUS,
  MULTIPLY,
  DIVIDE,
  POWER
};

std::unique_ptr<Node> CreateNode(BinaryOpType type);

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_REGISTRY_H_