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

#include "core/lang/logic.h"

#include <cmath>

#include "core/lang/binaryfn.h"
#include "core/lang/symbols.h"
#include "core/lang/unaryfn.h"

namespace calc {
namespace lang {

BinaryFn GetBinaryFn(BinaryOpType type) {
  switch (type) {
    case BinaryOpType::ADD: return &binaryfn::Add;
    case BinaryOpType::MINUS: return &binaryfn::Minus;
    case BinaryOpType::MULTIPLY: return &binaryfn::Multiply;
    case BinaryOpType::DIVIDE: return &binaryfn::Divide;
    case BinaryOpType::POWER: return &binaryfn::Power;
  }
}

UnaryFn GetUnaryFn(UnaryOpType type) {
  switch (type) {
    case (UnaryOpType::IDENTITY): return &unaryfn::Identity;
    case (UnaryOpType::NEGATE): return &unaryfn::Negate;
    case (UnaryOpType::SIN): return &unaryfn::Sin;
    case (UnaryOpType::COS): return &unaryfn::Cos;
    case (UnaryOpType::TAN): return &unaryfn::Tan;
    case (UnaryOpType::SINH): return &unaryfn::Sinh;
    case (UnaryOpType::COSH): return &unaryfn::Cosh;
    case (UnaryOpType::TANH): return &unaryfn::Tanh;
  }
}

Literal GetConstant(Constant type) {
  switch (type) {
    case Constant::E: return Literal(M_E);
    case Constant::PI: return Literal(M_PI);
  }
}

}  // namespace lang
}  // namespace calc
