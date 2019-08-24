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

#include "core/impl/nodes/priority.h"

#include <cstddef>

namespace calc {
namespace impl {
namespace nodes {
  
std::size_t Priority::inst_count_ = 0;

Priority::Priority(Precedence precedence)
    : index_(inst_count_++),
      precedence_(static_cast<std::size_t>(precedence)) {
  left_associative_ = false;
  switch (precedence) {
    case Precedence::TWO:
    case Precedence::FOUR:
    case Precedence::SIX:
      left_associative_ = true;
  }
}

bool operator==(const Priority& left, const Priority& right) {
  return left.index_ == right.index_;
}

bool operator!=(const Priority& left, const Priority& right) {
  return left.index_ != right.index_;
}

bool operator<(const Priority& left, const Priority& right) {
  if (left.precedence_ != right.precedence_) {
    return left.precedence_ < right.precedence_;
  }

  if (left.left_associative_) 
    return left.index_ > right.index_;

  return left.index_ < right.index_;
}

bool operator>(const Priority& left, const Priority& right) {
  if (left.precedence_ != right.precedence_) {
    return left.precedence_ > right.precedence_;
  }

  if (left.left_associative_) 
    return left.index_ < right.index_;

  return left.index_ > right.index_;
}

bool operator<=(const Priority& left, const Priority& right) {
  return left < right || left == right;
}

bool operator>=(const Priority& left, const Priority& right) {
  return left > right || left == right;
}

}  // namespace nodes
}  // namespace impl
}  // namespace calc
