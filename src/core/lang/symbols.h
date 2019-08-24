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

#ifndef CPPND_CAPSTONE_CALC_CORE_LANG_SYMBOLS_H_
#define CPPND_CAPSTONE_CALC_CORE_LANG_SYMBOLS_H_

#include <variant>

namespace calc {
namespace lang {

struct Literal {
  explicit Literal(float value) : value(value) {}
  const float value;
};

enum class Constant {
  E,
  PI
};

enum class BinaryOpType {
  ADD,
  MINUS,
  MULTIPLY,
  DIVIDE,
  POWER
};

enum class UnaryOpType {
  NEGATE,
  IDENTITY,
  SIN,
  COS,
  TAN,
  SINH,
  COSH,
  TANH
};

enum class MiscType {
  OPEN_BRACKET,
  CLOSE_BRACKET
};

using SymbolType = std::variant<
    Literal, Constant, BinaryOpType, UnaryOpType, MiscType>;
using BinaryFn = float (*)(float, float);
using UnaryFn = float (*)(float);

}  // namespace lang
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_LANG_SYMBOLS_H_
