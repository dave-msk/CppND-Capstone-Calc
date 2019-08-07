#include "paresr/fsm/factories.h"

#include <memory>
#include <string>
#include <vector>

#include "yaml-cpp/yaml.h"

#include "core/fsm/graph.h"

namespace calc {
namespace fsm {

std::unique_ptr<Graph<char>> CreateTokenizationGraph(
    const std::string& num_config_file,
    const std::vector<std::string>& symbols) {
  auto graph_ptr = std::make_unique<Graph<char>>();

  // 1. Define subgraph for numerals
  YAML::Node config = YAML::LoadFile(num_config_file);

  // 1.1 Construct nodes
  const YAML::Node &num_nodes = config["states"];
  for (auto it = num_nodes.begin(); it != num_nodes.end(); ++it) {
    const YAML::Node &node = *it;
    graph_ptr->AddState(node["id"].as<std::string>(),
                        node["terminal"].as<bool>());
  }

  // 1.2 Define transitions
  const YAML::Node &trans = config["transitions"];
  for (auto it = trans.begin(); it != trans.end(); ++it) {
    const YAML::Node &trans_def = *it;
    const std::string &src = trans_def["src"].as<std::string>();
    const std::string &dst = trans_def["dst"].as<std::string>();
    const std::string &trs = trans_def["transitions"].as<std::string>();
    for (auto c : trs) {
      graph_ptr->DefineTransition(src, dst, c);
    }
  }

  // 2. Define subgraph for symbols
  // This is actually a trie
  for (auto it = symbols.begin(); it != symbols.end(); ++it) {
    const std::string &symbol = *it;
    const std::size_t size = symbol.size();
    for (std::size_t i = 0; i < size; ++i) {
      const std::string src = symbol.substr(0, i);
      const std::string dst = symbol.substr(0, i+1);
      graph_ptr->AddState(dst, false);
      graph_ptr->DefineTransition(src, dst, symbol[i]);
      if (i == size - 1) {
        graph_ptr->SetStateTerminal(dst, true);
      }
    }
  }

  return graph_ptr;
}

}  // namespace fsm
}  // namespace calc
