#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_REGISTRY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_REGISTRY_H_

#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/ops/binary/type.h"

namespace calc {
namespace nodes {

std::unique_ptr<Node> CreateNode(BinaryOpType type);

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_REGISTRY_H_