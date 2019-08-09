#ifndef CPPND_CAPSTONE_CALC_CORE_PARSER_PARSER_H_
#define CPPND_CAPSTONE_CALC_CORE_PARSER_PARSER_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <variant>

#include "core/fsm/graph.h"
#include "core/nodes/node.h"
#include "core/nodes/numbers/type.h"
#include "core/nodes/ops/binary/type.h"
#include "core/nodes/ops/unary/type.h"
#include "core/parser/type.h"

namespace calc {
namespace parser {

class Parser {
 public:
  using NodeType = std::variant<::calc::nodes::Constant,
                                ::calc::nodes::Literal,
                                ::calc::nodes::BinaryOpType,
                                ::calc::nodes::UnaryOpType,
                                ::calc::nodes::MiscType>;
  
  explicit Parser(
      std::unique_ptr<::calc::fsm::Graph<SymbolType>> grammar_graph)
      : grammar_graph_(std::move(grammar_graph)) {}

  void AddSymbol(std::string symbol,
                 SymbolType symbol_type,
                 NodeType node_type);
  
  std::unique_ptr<Node> Parse(const std::vector<std::string>&);

 private:
  struct SymbolMeta {
    SymbolMeta(SymbolType symbol_type, NodeType node_type)
        : symbol_type(symbol_type), node_type(node_type) {}
    const SymbolType symbol_type;
    const NodeType node_type;
  };
  using MetaMap = std::unordered_map<std::string, SymbolMeta>;

  std::unordered_map<std::string, MetaMap> meta_map_; 
  std::unique_ptr<::calc::fsm::Graph<SymbolType>> grammar_graph_;
};

}  // namespace parser
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_PARSER_PARSER_H_
