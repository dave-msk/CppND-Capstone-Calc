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
