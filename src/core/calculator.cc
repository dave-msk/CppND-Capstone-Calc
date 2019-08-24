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
