#include "core/calculator.h"

#include <string>
#include <vector>
#include <exception>

#include "core/exception.h"

namespace {

void ValidateBrackets(const std::vector<std::string>& tokens) {
  int depth = 0;
  for (auto t : tokens) {
    if (t == "(")
      ++depth;
    else if (t == ")")
      --depth;
    
    if (depth < 0)
      throw ::calc::InvalidSyntax("Unpaired close brackets detected.");
  }
  if (depth != 0)
    throw ::calc::InvalidSyntax("Unpaired open brackets detected.");
}

}  // namespace

namespace calc {

std::string Calculator::Compute(const std::string& input) {
  try {
    // 1. Tokenize input
    std::vector tokens = tokenizer_->Tokenize(input);
    if (tokens.empty()) return "";

    // 2. Validate if brackets are balanced
    ValidateBrackets(tokens);

    // 3. Parse expression
    auto expr = parser_->Parse(tokens);

    // 4. Compute result
    float result = expr->GetValue();

    // 5. Return value
    return std::to_string(result);

  } catch (const std::exception& e) {
    return std::string(e.what());
  }
}

}  // namespace calc
