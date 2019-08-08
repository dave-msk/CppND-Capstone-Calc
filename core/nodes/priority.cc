#include "core/nodes/precedence.h"

#include <cstddef>

namespace calc {
namespace nodes {

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
}  // namespace calc
