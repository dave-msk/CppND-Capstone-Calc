#include "core/impl/nodes/binary.h"

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

BinaryOp::BinaryOp(Precedence precedence, ::calc::lang::BinaryFn func)
    : Node(precedence), func_(func) {}

float BinaryOp::ComputeValue() const {
  return func_(left->GetValue(), right->GetValue());
}

}  // namespace nodes 
}  // namespace impl
}  // namespace calc
