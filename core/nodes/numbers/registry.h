#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_REGISTRY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_REGISTRY_H_

#include <memory>

#include "core/nodes.node.h"

namespace calc {

enum class Constant {
  E,
  PI
}

std::unique_ptr<Node> CreateNode(Constant);
std::unique_ptr<Node> CreateNode(float);

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_REGISTRY_H_
