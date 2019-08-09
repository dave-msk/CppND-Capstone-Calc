#ifndef CPPND_CAPSTONE_CALC_CORE_TOKENIZER_H_
#define CPPND_CAPSTONE_CALC_CORE_TOKENIZER_H_

#include <memory>
#include <vector>

#include "core/fsm/graph.h"

namespace calc {
namespace tokens {

class Tokenizer {
 public:
  explicit Tokenizer(std::unique_ptr<fsm::Graph<char>>);

  std::vector<std::string> Tokenize(const std::string&) const;

 private:
  std::unique_ptr<::calc::fsm::Graph<char>> graph_;
};

}  // namespace tokens
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_TOKENIZER_H_
