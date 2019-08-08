#ifndef CPPND_CAPSTONE_CALC_PARSER_TYPE_H_
#define CPPND_CAPSTONE_CALC_PARSER_TYPE_H_

namespace calc {
namespace parser {

enum class SymbolType {
  CLOSE,
  OPEN,
  PREFIX,
  INFIX,
  SUFFIX,
  VALUE,
  FUNCTION
};

}  // namespace parser
}  // namespace calc
