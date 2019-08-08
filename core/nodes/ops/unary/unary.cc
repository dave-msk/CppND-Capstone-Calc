#include "core/nodes/ops/unary/unary.h"

#include "core/nodes/node.h"
#include "core/nodes/priority.h"

namespace calc {
namespace nodes {

UnaryOp::UnaryOp(Precedence prec, bool prefix_op, UnaryOp::UnaryFn func)
    : Node(prec), prefix_op_(prefix_op), func_(func) {}

float UnaryOp::ComputeValue() {
  if (prefix_op_) return func_(right_->ComputeValue());
  return func_(left_->ComputeValue());
}

FunctionOp::FunctionOp(UnaryOp::UnaryFn func)
    : UnaryOp(Precedence::MAX, true, func) {}

}  // namespace nodes
}  // namespace calc
