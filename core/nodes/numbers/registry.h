#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_REGISTRY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_REGISTRY_H_

#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/numbers/type.h"

namespace calc {
namespace nodes {

std::unique_ptr<Node> CreateNode(Constant);
std::unique_ptr<Node> CreateNode(const Literal&);

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_REGISTRY_H_
