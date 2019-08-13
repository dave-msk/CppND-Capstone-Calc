#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_TOKENIZER_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_TOKENIZER_H_

#include <memory>
#include <vector>

#include "core/expr.h"
#include "core/fsm/graph.h"

namespace calc {
namespace impl {
namespace parser {

class CharacterGraphTokenizer : public Tokenizer {
 public:
  explicit CharacterGraphTokenizer(std::unique_ptr<::calc::fsm::Graph<char>>);

  std::vector<std::string> Tokenize(const std::string&);

 private:
  std::unique_ptr<::calc::fsm::Graph<char>> graph_;
};

}  // namespace parser
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_TOKENIZER_H_
