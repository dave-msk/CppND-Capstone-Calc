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

#include "core/impl/parser/parser.h"

#include <memory>
#include <mutex>
#include <string>
#include <tuple>
#include <utility>
#include <variant>

#include "core/exception.h"
#include "core/expr.h"
#include "core/fsm/graph.h"
#include "core/impl/nodes/factories.h"
#include "core/impl/nodes/misc.h"
#include "core/impl/nodes/node.h"
#include "core/lang/symbols.h"
#include "core/lang/syntax.h"

namespace calc {
namespace impl {
namespace parser {

void GrammarGraphParser::AddSymbol(
    std::string symbol,
    ::calc::lang::SyntaxType syntax_type,
    ::calc::lang::SymbolType symbol_type) {
  for (auto it = grammar_graph_->cbegin(); it != grammar_graph_->cend(); ++it) {
    auto& state = it->second;
    if (state.trans_map.find(syntax_type) != state.trans_map.end()) {
      symbol_metas_.emplace(
          std::piecewise_construct,
          std::forward_as_tuple(it->first + "/<" + symbol + ">"),
          std::forward_as_tuple(syntax_type, symbol_type));
    }
  }
}

std::unique_ptr<::calc::Expression> GrammarGraphParser::Parse(
    const std::vector<std::string>& tokens) {
  using ::calc::lang::SymbolType;
  using ::calc::lang::SyntaxType;
  using ::calc::impl::nodes::Node;

  std::lock_guard<std::mutex> lock(mtx_);

  grammar_graph_->Reset();
  std::vector<SymbolType> symbol_types;
  for (const auto& token : tokens) {
    auto it = symbol_metas_.find(
        grammar_graph_->GetCurrentState() + "/<" + token + ">");

    // Case 1: Token is a valid symbol
    if (it != symbol_metas_.end()) {
      symbol_types.emplace_back(it->second.symbol_type);
      grammar_graph_->Step(it->second.syntax_type);
      continue;
    }

    // Case 2: Token is a valid floating point number
    try {
      float value = std::stof(token);
      if (!grammar_graph_->NextState(SyntaxType::VALUE).empty()) {
        symbol_types.emplace_back(::calc::lang::Literal(value));
        grammar_graph_->Step(SyntaxType::VALUE);
        continue;
      }
    } catch (std::invalid_argument) {}

    // Case 3: It is neither a valid symbol nor a valid floating point number.
    //   We conclude that the input expression is invalid.
    throw ::calc::InvalidSyntax(
        "Invalid symbol \"" + token + "\" at grammar state \""
        + grammar_graph_->GetCurrentState() + "\"");
  }

  // Check if the expression ends in a valid state.
  if (!grammar_graph_->IsTerminal())
    throw ::calc::InvalidSyntax("Incomplete expression");

  // Construct the expression tree.
  Node* root = new ::calc::impl::nodes::OpenBracket();
  Node* current = root;

  auto visit_fn = [](auto&& type) {
    return ::calc::impl::nodes::CreateNode(type);
  };
  for (SymbolType& symbol_type : symbol_types) {
    current = current->AddNode(std::visit(visit_fn, symbol_type));
  }

  // Climb to the real root and destroy the helper root.
  while (current != root) current = current->parent;
  // while (current->parent != root) current = current->parent;
  current = current->right;
  current->parent = nullptr;
  root->parent = root->left = root->right = nullptr;
  delete root;

  return std::unique_ptr<::calc::Expression>(current);
}

}  // namespace parser
}  // namespace impl
}  // namespace calc
