#ifndef CPPND_CAPSTONE_CALC_CORE_PARSER_GRAMMAR_H_
#define CPPND_CAPSTONE_CALC_CORE_PARSER_GRAMMAR_H_

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

class Grammar {
 public:
  using NodeType = std::variant<::calc::nodes::Constant,
                                ::calc::nodes::BinaryOpType,
                                ::calc::nodes::UnaryOpType,
                                ::calc::nodes::MiscType>;
  
  Grammar() = default;

  void AddSymbol(std::string symbol,
                 SymbolType symbol_type,
                 NodeType node_type);
  
  void AddRule(std::string src, std::string dst, SymbolType symbol_type);
  
  std::unique_ptr<Node> Parse(const std::vector<std::string>&);

 private:
  struct SymbolMeta {
    const SymbolType symbol_type;
    const NodeType node_type;
  };
  using MetaMap = std::unordered_map<std::string, SymbolMeta>;

  std::unordered_map<std::string, MetaMap> states_to_meta_; 
  ::calc::fsm::Graph<SymbolType> fsm_graph_;
};

}  // namespace parser
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_PARSER_GRAMMAR_H_
