#include "parser/nodes/ops/binary.h"

#include "parser/nodes/node.h"
#include "parser/nodes/priority.h"

namespace calc {

BinaryOp::BinaryOp(Precedence precedence, BinaryOp::BinaryFn func)
    : Node(precedence), func_(func) {}

float BinaryOp::ComputeValue() {
  return func_(left_->GetValue(), right_->GetValue());
}
  
}  // namespace calc
