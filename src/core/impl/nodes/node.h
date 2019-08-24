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

#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NODE_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NODE_H_

#include <memory>

#include "core/expr.h"
#include "core/impl/nodes/priority.h"

namespace calc {
namespace impl {
namespace nodes {

class Node : public ::calc::Expression {
 public:
  Node(Precedence precedence) : priority(precedence) {}
  virtual ~Node();

  float GetValue() const;
  Node* AddNode(std::unique_ptr<Node>);
  
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
  const Priority priority;

 private:
  virtual bool IsValidParent(const Node&) const;
  virtual float ComputeValue() const;
  virtual Node* ExtendTree(Node*);
};

}  // namespace nodes
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NODE_H_
