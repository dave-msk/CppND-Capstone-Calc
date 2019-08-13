#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_PARSER_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_PARSER_H_

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <variant>

#include "core/expr.h"
#include "core/fsm/graph.h"
#include "core/impl/nodes/node.h"
#include "core/lang/symbols.h"
#include "core/lang/syntax.h"

namespace calc {
namespace impl {
namespace parser {

class GrammarGraphParser : public Parser {
 public:
  explicit GrammarGraphParser(
      std::unique_ptr<
          ::calc::fsm::Graph<::calc::lang::SyntaxType>> grammar_graph)
      : grammar_graph_(std::move(grammar_graph)) {}

  void AddSymbol(std::string symbol,
                 ::calc::lang::SyntaxType syntax_type,
                 ::calc::lang::SymbolType symbol_type);
  
  std::unique_ptr<Expression> Parse(const std::vector<std::string>&);

 private:
  struct SymbolMeta {
    SymbolMeta(::calc::lang::SyntaxType syntax_type,
               ::calc::lang::SymbolType symbol_type)
        : syntax_type(syntax_type), symbol_type(symbol_type) {}
    const ::calc::lang::SyntaxType syntax_type;
    const ::calc::lang::SymbolType symbol_type;
  };

  std::unordered_map<std::string, SymbolMeta> symbol_metas_; 
  std::unique_ptr<::calc::fsm::Graph<::calc::lang::SyntaxType>> grammar_graph_;
  std::mutex mtx_;
};

}  // namespace parser
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_PARSER_PARSER_H_
