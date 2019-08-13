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
