/* Copyright 2019 Siu-Kei Muk (David). All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

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
