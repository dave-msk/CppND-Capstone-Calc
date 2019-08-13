#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_FACTORIES_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_FACTORIES_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "core/expr.h"
#include "core/fsm/graph.h"
#include "core/lang/syntax.h"

namespace calc {
namespace impl {
namespace parser {

std::unique_ptr<::calc::fsm::Graph<char>> CreateTokenizationGraph(
    const std::string&,
    const std::unordered_set<std::string>&);

std::unique_ptr<::calc::fsm::Graph<::calc::lang::SyntaxType>>
CreateGrammarGraph(
    const std::string&,
    const std::unordered_map<char, ::calc::lang::SyntaxType>&);

std::unique_ptr<::calc::Tokenizer> CreateTokenizer(
    std::unique_ptr<::calc::fsm::Graph<char>>);

std::unique_ptr<::calc::Parser> CreateParser(
    std::unique_ptr<::calc::fsm::Graph<::calc::lang::SyntaxType>>,
    const std::vector<::calc::lang::Element>&);

}  // namespace parser
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_FACTORIES_H_
