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

#include "core/impl/nodes/factories.h"

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/binary.h"
#include "core/impl/nodes/unary.h"
#include "core/impl/nodes/misc.h"
#include "core/impl/nodes/priority.h"
#include "core/impl/nodes/number.h"
#include "core/lang/logic.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

std::unique_ptr<Node> CreateNode(const ::calc::lang::Literal& literal) {
  return std::unique_ptr<Node>(new Number(literal.value));
}

std::unique_ptr<Node> CreateNode(::calc::lang::Constant constant) {
  return CreateNode(::calc::lang::GetConstant(constant));
}

std::unique_ptr<Node> CreateNode(::calc::lang::BinaryOpType type) {
  using ::calc::lang::BinaryOpType;

  Precedence prec;
  ::calc::lang::BinaryFn func = ::calc::lang::GetBinaryFn(type);

  switch (type) {
    case BinaryOpType::ADD:
    case BinaryOpType::MINUS: {
      prec = Precedence::TWO;
      break;
    }
    case BinaryOpType::MULTIPLY:
    case BinaryOpType::DIVIDE: {
      prec = Precedence::FOUR;
      break;
    }
    case BinaryOpType::POWER: {
      prec = Precedence::FIVE;
      break;
    }
  }

  return std::unique_ptr<Node>(new BinaryOp(prec, func));
}

std::unique_ptr<Node> CreateNode(::calc::lang::MiscType type) {
  using ::calc::lang::MiscType;

  switch (type) {
    case MiscType::OPEN_BRACKET:
      return std::unique_ptr<Node>(new OpenBracket());
    case MiscType::CLOSE_BRACKET:
      return std::unique_ptr<Node>(new CloseBracket());
  }
}

std::unique_ptr<Node> CreateNode(::calc::lang::UnaryOpType type) {
  using ::calc::lang::UnaryOpType;
  
  ::calc::lang::UnaryFn func = ::calc::lang::GetUnaryFn(type);

  switch (type) {
    case UnaryOpType::NEGATE:
    case UnaryOpType::IDENTITY: {
      return std::unique_ptr<Node>(new UnaryOp(Precedence::THREE, true, func));
    }
    case UnaryOpType::SIN:
    case UnaryOpType::COS:
    case UnaryOpType::TAN:
    case UnaryOpType::SINH:
    case UnaryOpType::COSH:
    case UnaryOpType::TANH: {
      return std::unique_ptr<Node>(new FunctionOp(func));
    }
  }
}

}  // namespace nodes
}  // namespace impl
}  // namespace calc
