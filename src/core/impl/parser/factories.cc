#include "core/impl/parser/factories.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "yaml-cpp/yaml.h"

#include "core/expr.h"
#include "core/fsm/graph.h"
#include "core/impl/parser/parser.h"
#include "core/impl/parser/tokenizer.h"
#include "core/lang/syntax.h"

namespace calc {
namespace impl {
namespace parser {

std::unique_ptr<::calc::fsm::Graph<char>> CreateTokenizationGraph(
    const std::string& num_config_file,
    const std::unordered_set<std::string>& symbols) {
  auto graph = std::make_unique<::calc::fsm::Graph<char>>();

  // 1. Define subgraph for numerals
  YAML::Node config = YAML::LoadFile(num_config_file);

  // 1.1 Construct nodes
  const YAML::Node& num_nodes = config["states"];
  for (auto it = num_nodes.begin(); it != num_nodes.end(); ++it) {
    const YAML::Node& node = *it;
    graph->AddState(node["id"].as<std::string>(),
                    node["terminal"].as<bool>());
  }

  // 1.2 Define transitions
  const YAML::Node& trans = config["transitions"];
  for (auto it = trans.begin(); it != trans.end(); ++it) {
    const YAML::Node& trans_def = *it;
    const std::string& src = trans_def["src"].as<std::string>();
    const std::string& dst = trans_def["dst"].as<std::string>();
    const std::string& trs = trans_def["transitions"].as<std::string>();
    for (auto c : trs) {
      graph->DefineTransition(src, dst, c);
    }
  }

  // 2. Define subgraph for symbols
  // This is actually a trie
  for (auto symbol : symbols) {
    const std::size_t size = symbol.size();
    for (std::size_t i = 0; i < size; ++i) {
      const std::string src = symbol.substr(0, i);
      const std::string dst = symbol.substr(0, i+1);
      graph->AddState(dst, false);
      graph->DefineTransition(src, dst, symbol[i]);
      if (i == size - 1) {
        graph->SetStateTerminal(dst, true);
      }
    }
  }

  return graph;
}

std::unique_ptr<::calc::fsm::Graph<::calc::lang::SyntaxType>>
CreateGrammarGraph(
    const std::string& config_file,
    const std::unordered_map<char, ::calc::lang::SyntaxType>& syntax_map) {
  auto graph =
      std::make_unique<::calc::fsm::Graph<::calc::lang::SyntaxType>>();

  // 0. Load grammar configuration
  YAML::Node config = YAML::LoadFile(config_file);

  // 1. Construct graph states
  const YAML::Node& states = config["states"];
  for (auto it = states.begin(); it != states.end(); ++it) {
    const YAML::Node& state = *it;
    graph->AddState(state["id"].as<std::string>(),
                    state["terminal"].as<bool>());
  }

  // 2. Define transitions
  const YAML::Node& trans = config["transitions"];
  for (auto it = trans.begin(); it != trans.end(); ++it) {
    const YAML::Node& trans_def = *it;
    const std::string& src = trans_def["src"].as<std::string>();
    const std::string& dst = trans_def["dst"].as<std::string>();
    const std::string& trs = trans_def["transitions"].as<std::string>();
    for (auto c : trs) graph->DefineTransition(src, dst, syntax_map.at(c));
  }

  return graph;
}

std::unique_ptr<::calc::Tokenizer> CreateTokenizer(
    std::unique_ptr<::calc::fsm::Graph<char>> graph) {
  return std::unique_ptr<::calc::Tokenizer>(
      new CharacterGraphTokenizer(std::move(graph)));
}

std::unique_ptr<::calc::Parser> CreateParser(
    std::unique_ptr<::calc::fsm::Graph<::calc::lang::SyntaxType>> grammar_graph,
    const std::vector<::calc::lang::Element>& vocabulary) {
  GrammarGraphParser* parser = new GrammarGraphParser(std::move(grammar_graph));
  for (const auto& elem : vocabulary) {
    parser->AddSymbol(elem.symbol, elem.syntax_type, elem.symbol_type);
  }
  return std::unique_ptr<::calc::Parser>(parser);
}

}  // namespace parser
}  // namespace impl
}  // namespace calc
