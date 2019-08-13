#include "core/impl/nodes/unary.h"

#include <cmath>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

UnaryOp::UnaryOp(Precedence prec, bool prefix_op, ::calc::lang::UnaryFn func)
    : Node(prec), prefix_op_(prefix_op), func_(func) {}

float UnaryOp::ComputeValue() const {
  if (prefix_op_) return func_(right->GetValue());
  return func_(left->GetValue());
}

FunctionOp::FunctionOp(::calc::lang::UnaryFn func)
    : UnaryOp(Precedence::MAX, true, func) {}

}  // namespace nodes
}  // namespace impl
}  // namespace calc
