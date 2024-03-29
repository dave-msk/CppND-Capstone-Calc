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

#ifndef CPPND_CAPSTONE_CALC_CORE_FSM_GRAPH_H_
#define CPPND_CAPSTONE_CALC_CORE_FSM_GRAPH_H_

#include <tuple>
#include <unordered_map>
#include <utility>

namespace calc {
namespace fsm {

template<typename Trans>
class Graph {
 public:
  struct State {
    State(std::string id, bool terminal)
        : kId(std::move(id)), terminal(terminal) {}

    const std::string kId;
    bool terminal;
    std::unordered_map<Trans, std::string> trans_map;
  };

  Graph();

  bool IsTerminal() const;
  std::string NextState(const Trans&) const;
  std::string GetCurrentState() const;
  auto cbegin() const;
  auto cend() const;

  bool Step(const Trans&);
  bool HasState(const std::string&);
  bool AddState(std::string, bool);
  bool SetStateTerminal(const std::string&, bool);
  bool DefineTransition(const std::string&, const std::string&, Trans);
  bool RemoveTransition(const std::string&, const Trans&);
  
  void Reset();
  
 private:
  std::unordered_map<std::string, State> states_;
  std::string curr_state_id_;
};

template<typename Trans>
Graph<Trans>::Graph() : curr_state_id_("") {
  AddState("", false);
}

template<typename Trans>
bool Graph<Trans>::IsTerminal() const {
  return states_.find(curr_state_id_)->second.terminal;
}

template<typename Trans>
std::string Graph<Trans>::NextState(const Trans& transition) const {
  auto state_it = states_.find(curr_state_id_);
  auto id_it = state_it->second.trans_map.find(transition);
  return (id_it == state_it->second.trans_map.end()) ? "" : id_it->second;
}

template<typename Trans>
std::string Graph<Trans>::GetCurrentState() const {
  return curr_state_id_;
}

template<typename Trans>
auto Graph<Trans>::cbegin() const {
  return states_.cbegin();
}

template<typename Trans>
auto Graph<Trans>::cend() const {
  return states_.cend();
}

template<typename Trans>
bool Graph<Trans>::Step(const Trans& transition) {
  std::string next_id = NextState(transition);
  if (next_id.empty()) return false;
  curr_state_id_ = std::move(next_id);
  return true;
}

template<typename Trans>
bool Graph<Trans>::HasState(const std::string& id) {
  return states_.find(id) != states_.end();
}

template<typename Trans>
bool Graph<Trans>::AddState(std::string id, bool terminal) {
  if (HasState(id)) return false;
  states_.emplace(std::piecewise_construct,
                  std::forward_as_tuple(id),
                  std::forward_as_tuple(id, terminal));
  return true;
}

template<typename Trans>
bool Graph<Trans>::SetStateTerminal(const std::string& id, bool terminal) {
  if (!HasState(id)) return false;
  auto state_it = states_.find(id);
  state_it->second.terminal = terminal;
  return true;
}


template<typename Trans>
bool Graph<Trans>::DefineTransition(const std::string& src_id,
                                    const std::string& dst_id,
                                    Trans transition) {
  if (!HasState(src_id) || !HasState(dst_id)) return false;
  
  auto state_it = states_.find(src_id);
  state_it->second.trans_map.emplace(transition, dst_id);
  return true;
}

template<typename Trans>
bool Graph<Trans>::RemoveTransition(const std::string& id,
                                    const Trans& transition) {
  if (!HasState(id)) return false;
  auto state_it = states_.find(id);
  auto& state = state_it->second;
  auto trans_it = state.trans_map.find(transition);
  if (trans_it == state.trans_map.end()) return false;
  state.trans_map.erase(trans_it);
  return true;
}

template<typename Trans>
void Graph<Trans>::Reset() {
  curr_state_id_ = "";
}

}  // namespace fsm
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_FSM_GRAPH_H_
