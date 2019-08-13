#ifndef CPPND_CAPSTONE_CALC_CORE_CALCULATOR_H_
#define CPPND_CAPSTONE_CALC_CORE_CALCULATOR_H_

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "core/expr.h"

namespace calc {

class Calculator {
 public:
  Calculator(std::unique_ptr<Tokenizer> tokenizer,
             std::unique_ptr<Parser> parser)
      : tokenizer_(std::move(tokenizer)), parser_(std::move(parser)) {}

  std::string Compute(const std::string&);
 
 private:
  std::unique_ptr<Tokenizer> tokenizer_;
  std::unique_ptr<Parser> parser_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_CALCULATOR_H_
