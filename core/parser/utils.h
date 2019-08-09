#ifndef CPPND_CAPSTONE_CALC_CORE_PARSER_UTILS_H_
#define CPPND_CAPSTONE_CALC_CORE_PARSER_UTILS_H_

#include <memory>
#include <string>

#include "core/fsm/graph.h"
#include "core/parser/parser.h"
#include "core/parser/type.h"

namespace calc {
namespace parser {

std::unique_ptr<::calc::fsm::Graph<SymbolType>> CreateGrammarGraph(
    const std::string& config_file);

std::unique_ptr<Parser> CreateParser(
    std::unique_ptr<::calc::fsm::Graph<SymbolType>> grammar_graph);

}  // namespace parser
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_PARSER_UTILS_H_
