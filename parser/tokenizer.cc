#include "parser/tokenizer.h"

#include <memory>
#include <sstream>
#include <utility>
#include <vector>

#include "parser/fsm/graph.h"
#include "parser/exception.h"

namespace calc {

Tokenizer::Tokenizer(std::unique_ptr<fsm::Graph<char>> graph)
    : graph_(std::move(graph)) {}

std::vector<std::string> Tokenizer::Tokenize(const std::string& input) const {
  std::vector<std::string> tokens;

  std::stringstream ss;
  for (std::size_t i = 0; i < input.size(); ++i) {
    char c = input[i];
    if (graph_.Step(c)) continue;
    std::string token = ss.str();

    if (graph_.IsTerminal()) {
      tokens.emplace_back(token);
      ss.clear();
      ss.str(std::string());
    } else if (!token.empty()) {
      // TODO: Throw project-defined error for invalid tokens
      throw InvalidTokenException("Unknown token: " + token);
    }

    if (c == ' ') continue;
    if (!graph_.Step(c)) {
      // TODO: Throw project-defined error for invalid tokens
      throw InvalidTokenException(
          "Unable to parse token at index: " + std::to_string(i));
    }
  }

  if (!ss.str().empty()) {
    tokens.emplace_back(ss.str());
  }

  return tokens;
}

}  // namespace calc