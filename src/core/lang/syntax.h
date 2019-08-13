#ifndef CPPND_CAPSTONE_CALC_CORE_LANG_SYNTAX_H_
#define CPPND_CAPSTONE_CALC_CORE_LANG_SYNTAX_H_

#include "core/lang/symbols.h"

namespace calc {
namespace lang {

enum class SyntaxType {
  PREFIX,
  INFIX,
  SUFFIX,
  VALUE,
  FUNCTION,
  OPEN,
  CLOSE
};

struct Element {
  Element(std::string symbol,
          SyntaxType syntax_type,
          SymbolType symbol_type)
      : symbol(std::move(symbol)),
        syntax_type(syntax_type),
        symbol_type(std::move(symbol_type)) {}

  const std::string symbol;
  const SyntaxType syntax_type;
  const SymbolType symbol_type;
};

}  // namespace lang
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_LANG_SYNTAX_H_
