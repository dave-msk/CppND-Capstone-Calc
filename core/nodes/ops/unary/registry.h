#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_REGISTRY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_REGISTRY_H_

#include <memory>

#include "core/nodes/node.h"

namespace calc {

enum class UnaryOpType {
  NEGATE,
  IDENTITY,
  SIN,
  COS,
  TAN,
  SINH,
  COSH,
  TANH
};

std::unique_ptr<Node> CreateNode(UnaryOpType);

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_REGISTRY_H_
