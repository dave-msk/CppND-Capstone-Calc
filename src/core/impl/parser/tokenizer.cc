#include "core/impl/parser/tokenizer.h"

#include <memory>
#include <mutex>
#include <sstream>
#include <utility>
#include <vector>

#include "core/fsm/graph.h"
#include "core/exception.h"

namespace calc {
namespace impl {
namespace parser {

CharacterGraphTokenizer::CharacterGraphTokenizer(
    std::unique_ptr<::calc::fsm::Graph<char>> graph)
    : graph_(std::move(graph)) {}

std::vector<std::string>
CharacterGraphTokenizer::Tokenize(const std::string& input) {
  std::lock_guard<std::mutex> lock(mtx_);

  graph_->Reset();
  std::vector<std::string> tokens;

  std::stringstream ss;
  for (std::size_t i = 0; i < input.size(); ++i) {
    char c = input[i];
    if (graph_->Step(c)) {
      ss << c;
      continue;
    }
    std::string token = ss.str();

    if (graph_->IsTerminal()) {
      tokens.emplace_back(token);
      ss.clear();
      ss.str(std::string());
      graph_->Reset();
    } else if (!token.empty()) {
      throw InvalidToken("Unknown token: " + token);
    }

    if (c == ' ') continue;
    if (graph_->Step(c)) {
      ss << c;
    } else {
      throw InvalidToken(
          "Unable to parse token at index: " + std::to_string(i));
    }
  }

  if (!ss.str().empty()) {
    tokens.emplace_back(ss.str());
  }

  return tokens;
}

}  // namespace parser
}  // namespace impl
}  // namespace calc
