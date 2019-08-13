#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_FACTORIES_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_FACTORIES_H_

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

std::unique_ptr<Node> CreateNode(const ::calc::lang::Literal&);
std::unique_ptr<Node> CreateNode(::calc::lang::Constant);
std::unique_ptr<Node> CreateNode(::calc::lang::BinaryOpType);
std::unique_ptr<Node> CreateNode(::calc::lang::UnaryOpType);
std::unique_ptr<Node> CreateNode(::calc::lang::MiscType);

}  // namespace nodes
}  // namespace ipml
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_FACTORIES_H_
