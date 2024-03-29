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

#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_TOKENIZER_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_TOKENIZER_H_

#include <memory>
#include <mutex>
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
  std::mutex mtx_;
};

}  // namespace parser
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_TOKENIZER_H_
