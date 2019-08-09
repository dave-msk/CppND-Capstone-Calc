#include "core/parser/parser.h"

#include <memory>
#include <string>
#include <tuple>
#include <utility>
#include <variant>

#include "core/fsm/graph.h"
#include "core/nodes/node.h"
#include "core/nodes/numbers/registry.h"
#include "core/nodes/ops/binary/registry.h"
#include "core/nodes/ops/unary/registry.h"
#include "core/nodes/others/registry.h"
#include "core/nodes/others/type.h"
#include "core/parser/type.h"

namespace calc {
namespace parser {

void Parser::AddSymbol(std::string symbol,
                       SymbolType symbol_type,
                       NodeType node_type) {
  for (auto it = grammar_graph_.cbegin(); it != grammar_graph_.cend(); ++it) {
    auto& state = it->second;
    if (state.trans_map.find(symbol_type) != state.trans_map.end()) {
      meta_map_.emplace(
          std::piecewise_construct,
          std::forward_as_tuple(it->first + "/<" + symbol + ">"),
          std::forward_as_tuple(symbol_type, node_type));
    }
  }
}

std::unique_ptr<Node> Parse(const std::vector<std::string>& tokens) {
  grammar_graph_->Reset();
  std::vector<NodeType> node_types;
  for (const auto& token : tokens) {
    auto it = meta_map_.find(
        grammar_graph_->GetCurrentState() + "/<" + token + ">");

    // Case 1: Token is a valid symbol
    if (it != meta_map_.end()) {
      node_types.emplace_back(it->second.node_type);
      grammar_graph_->Step(it->second.symbol_type);
      continue;
    }

    // Case 2: Token is a valid floating point number
    try {
      float value = std::stof(token);
      if (!grammar_graph_->NextState(SymbolType::VALUE).empty()) {
        node_types.emplace_back(::calc::nodes::Literal(value));
        grammar_graph_->Step(SymbolType::VALUE);
        continue;
      }
    } catch (std::invalid_argument) {}

    // Case 3: It is neither a valid symbol nor a valid floating point number.
    //   We conclude that the input expression is invalid.
    return nullptr;
  }
  
  // Check if the expression ends in a valid state.
  if (!grammar_graph_->IsTerminal()) return nullptr;
  
  // Construct the expression tree.
  Node* root = new ::calc::nodes::OpenBracket();
  Node* current = root;
  auto visit_fn = [](auto&& type) { return ::calc::nodes::CreateNode(type); };
  for (NodeType& node_type : node_types) {
    current = current->AddNode(std::visit(visit_fn, node_type));
  }

  // Climb to the real root and destroy the helper root.
  while (current->parent_ != root) current = current->parent_;
  root->left_ = nullptr;
  root->right_ = nullptr;
  current->parent_ = nullptr;
  delete root;

  return std::unique_ptr<Node>(current);
}

}  // namespace parser
}  // namespace calc
