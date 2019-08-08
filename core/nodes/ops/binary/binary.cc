#include "core/nodes/ops/binary.h"

#include "core/nodes/node.h"
#include "core/nodes/priority.h"

namespace calc {
namespace nodes {

BinaryOp::BinaryOp(Precedence precedence, BinaryOp::BinaryFn func)
    : Node(precedence), func_(func) {}

float BinaryOp::ComputeValue() {
  return func_(left_->GetValue(), right_->GetValue());
}

}  // namespace nodes 
}  // namespace calc
