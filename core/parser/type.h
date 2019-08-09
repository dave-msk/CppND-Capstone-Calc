#ifndef CPPND_CAPSTONE_CALC_PARSER_TYPE_H_
#define CPPND_CAPSTONE_CALC_PARSER_TYPE_H_

namespace calc {
namespace parser {

enum class SymbolType {
  PREFIX,
  INFIX,
  SUFFIX,
  VALUE,
  FUNCTION,
  OPEN,
  CLOSE
};

}  // namespace parser
}  // namespace calc
