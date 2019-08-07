#include "core/nodes/ops/unary/registry.h"

#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/priority.h"
#include "core/nodes/ops/unary/unary.h"
#include "core/nodes/ops/unary/functions.h"

namespace calc {

std::unique_ptr<Node> CreateNode(UnaryOpType type) {
  switch (type) {
    case UnaryOpType::NEGATE: {
      return std::unique_ptr<Node>(
          new UnaryOp(Precedence::THREE, true, &unaryfn::Negate));
    }
    case UnaryOpType::IDENTITY: {
      return std::unique_ptr<Node>(
          new UnaryOp(Precedence::THREE, true, &unaryfn::Identity));
    }
    case UnaryOpType::SIN: {
      return std::unique_ptr<Node>(new FunctionOp(&unaryfn::Sin));
    }
    case UnaryOpType::COS: {
      return std::unique_ptr<Node>(new FunctionOp(&unaryfn::Cos));
    }
    case UnaryOpType::TAN: {
      return std::unique_ptr<Node>(new FunctionOp(&unaryfn::Tan));
    }
    case UnaryOpType::SINH: {
      return std::unique_ptr<Node>(new FunctionOp(&unaryfn::Sinh));
    }
    case UnaryOpType::COSH: {
      return std::unique_ptr<Node>(new FunctionOp(&unaryfn::Cosh));
    }
    case UnaryOpType::TANH: {
      return std::unique_ptr<Node>(new FunctionOp(&unaryfn::Tanh));
    }
  }
}

}  // namespace calc