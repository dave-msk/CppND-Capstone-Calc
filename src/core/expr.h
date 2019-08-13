#ifndef CPPND_CAPSTONE_CALC_CORE_EXPR_H_
#define CPPND_CAPSTONE_CALC_CORE_EXPR_H_

#include <vector>

namespace calc {

class Expression {
 public:
  virtual float GetValue() const = 0;
};

class Parser {
 public:
  virtual std::unique_ptr<Expression>
  Parse(const std::vector<std::string>&) = 0;
};

class Tokenizer {
 public:
  virtual std::vector<std::string> Tokenize(const std::string&) = 0;
};

}  // namespace expr

#endif  // CPPND_CAPSTONE_CALC_CORE_EXPR_H_
