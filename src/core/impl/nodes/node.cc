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

#include "core/impl/nodes/node.h"

#include <memory>

namespace calc {
namespace impl {
namespace nodes {

Node::~Node() {
  delete left, right;
}

float Node::GetValue() const {
  return ComputeValue();
}

Node* Node::AddNode(std::unique_ptr<Node> node) {
  Node* raw_node = node.release();
  Node* new_parent = this;

  while (!raw_node->IsValidParent(*new_parent)) {
    new_parent = new_parent->parent;
  }
  return raw_node->ExtendTree(new_parent);
}

bool Node::IsValidParent(const Node& node) const {
  return node.priority < priority;
}

float Node::ComputeValue() const {
  return 0.0f;
}

Node* Node::ExtendTree(Node* new_parent) {
  parent = new_parent;
  if (parent->right != nullptr && left == nullptr) {
    left = parent->right;
    left->parent = this;
  }
  parent->right = this;
  return this;
}

}  // namespace nodes
}  // namespace impl
}  // namespace calc
