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

#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_BINARY_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_BINARY_H_

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

class BinaryOp : public Node {
 public:
  BinaryOp(Precedence, ::calc::lang::BinaryFn);

 private:
  virtual float ComputeValue() const;

  const ::calc::lang::BinaryFn func_;
};

}  // namespace nodes
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_BINARY_H_
