#include "core/parser/utils.cc"

#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "yaml-cpp/yaml.h"

#include "core/fsm/graph.h"
#include "core/parser/parser.h"
#include "core/parser/type.h"

namespace {

using Constant = ::calc::nodes::Constant;
using BinaryOpType = ::calc::nodes::BinaryOpType;
using UnaryOpType = ::calc::nodes::UnaryOpType;
using MiscType = ::calc::nodes::MiscType;
using NodeType = ::calc::parser::Parser::NodeType;
using SymbolType = ::calc::parser::SymbolType;
using Entity = std::tuple<std::string, SymbolType, NodeType>;
                
constexpr std::unordered_map<char, SymbolType> sym_type_map = {
    {'P', SymbolType::PREFIX},
    {'I', SymbolType::INFIX},
    {'S', SymbolType::SUFFIX},
    {'V', SymbolType::VALUE},
    {'F', SymbolType::FUNCTION},
    {'O', SymbolType::OPEN},
    {'C', SymbolType::CLOSE}
};

const std::vector<Entity> entities = {
    {"(", SymbolType::OPEN, NodeType(MiscType::OPEN_BRACKET)},
    {")", SymbolType::CLOSE, NodeType(MiscType::CLOSE_BRACKET)},
    {"+", SymbolType::INFIX, NodeType(BinaryOpType::ADD)},
    {"-", SymbolType::INFIX, NodeType(BinaryOpType::MINUS)},
    {"*", SymbolType::INFIX, NodeType(BinaryOpType::MULTIPLY)},
    {"/", SymbolType::INFIX, NodeType(BinaryOpType::DIVIDE)},
    {"+", SymbolType::PREFIX, NodeType(UnaryOpType::IDENTITY)},
    {"-", SymbolType::PREFIX, NodeType(UnaryOpType::NEGATE)},
    {"pi", SymbolType::VALUE, NodeType(Constant::PI)},
    {"e", SymbolType::VALUE, NodeType(Constant::E)},
    {"sin", SymbolType::FUNCTION, NodeType(UnaryOpType::SIN)},
    {"cos", SymbolType::FUNCTION, NodeType(UnaryOpType::COS)},
    {"tan", SymbolType::FUNCTION, NodeType(UnaryOpType::TAN)},
    {"sinh", SymbolType::FUNCTION, NodeType(UnaryOpType::SINH)},
    {"cosh", SymbolType::FUNCTION, NodeType(UnaryOpType::COSH)},
    {"tanh", SymbolType::FUNCTION, NodeType(UnaryOpType::TANH)}
};

}  // namespace

namespace calc {
namespace parser {

std::unique_ptr<::calc::fsm::Graph<SymbolType>> CreateGrammarGraph(
    const std::string& config_file) {
  auto graph = std::make_unique<::calc::fsm::Graph<SymbolType>>();

  // 0. Load grammar configuration
  YAML::Node config = YAML::LoadFile(config_file);

  // 1. Construct graph states
  const YAML::Node& states = config["states"]
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
    for (auto c : trs) graph->DefineTransition(src, dst, ::sym_type_map.at(c));
  }

  return graph;
}

std::unique_ptr<Parser> CreateParser(
    std::unique_ptr<::calc::fsm::Graph<SymbolType>> grammar_graph,
    const std::vector<Entity>& entities) {
  auto parser = std::make_unique<Parser>(std::move(grammar_graph));
  for (const auto& entity : entities) {
    const auto& [symbol, symbol_type, node_type] = entity;
    parser->AddSymbol(symbol, symbol_type, node_type);
  }
  return parser;
}

}  // namespace parser
}  // namespace calc
