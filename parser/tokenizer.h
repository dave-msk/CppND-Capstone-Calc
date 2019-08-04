#ifndef CPPND_CAPSTONE_CALC_PARSER_TOKENIZER_H_
#define CPPND_CAPSTONE_CALC_PARSER_TOKENIZER_H_

#include <memory>
#include <vector>

#include "parser/fsm/graph.h"

namespace calc {

class Tokenizer {
 public:
  explicit Tokenizer(std::unique_ptr<fsm::Graph<char>>);

  std::vector<std::string> Tokenize(const std::string&) const;

 private:
  std::unique_ptr<fsm::Graph<char>> graph_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_PARSER_TOKENIZER_H_
