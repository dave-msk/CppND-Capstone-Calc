#include "core/nodes/ops/binary/registry.h"

#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/ops/binary/binary.h"
#include "core/nodes/ops/binary/functions.h"
#include "core/nodes/ops/binary/type.h"
#include "core/nodes/priority.h"

namespace calc {
namespace nodes {

std::unique_ptr<Node> CreateNode(BinaryOpType type) {
  Precedence prec;
  BinaryOp::BinaryFn func = nullptr;

  switch (type) {
    case BinaryOpType::ADD: {
      func =& binaryfn::Add;
      prec = Precedence::TWO;
      break;
    }
    case BinaryOpType::MINUS: {
      func =& binaryfn::Minus;
      prec = Precedence::TWO;
      break;
    }
    case BinaryOpType::MULTIPLY: {
      func =& binaryfn::Multiply;
      prec = Precedence::FOUR;
      break;
    }
    case BinaryOpType::DIVIDE: {
      func =& binaryfn::Divide;
      prec = Precedence::FOUR;
      break;
    }
    case BinaryOpType::POWER: {
      func =& binaryfn::Power;
      prec = Precedence::FIVE;
      break;
    }
  }

  if (func != nullptr) {
    return std::unique_ptr<Node>(new BinaryOp(prec, func));
  }
  return nullptr;
}

}  // namespace nodes
}  // namespace calc
