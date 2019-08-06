#include "parser/nodes/ops/prefix.h"

#include "parser/nodes/node.h"
#include "parser/nodes/priority.h"

namespace calc {

PrefixOp::PrefixOp(Precedence precedence, PrefixOp::UnaryFn func)
    : Node(precedence), func_(func) {}

float PrefixOp::ComputeValue() {
  return func_(right_->GetValue());
}

}  // namespace calc
