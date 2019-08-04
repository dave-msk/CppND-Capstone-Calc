#ifndef CPPND_CAPSTONE_CALC_PARSER_FSM_GRAPH_H_
#define CPPND_CAPSTONE_CALC_PARSER_FSM_GRAPH_H_

#include <tuple>
#include <unordered_map>
#include <utility>

namespace calc {
namespace fsm {

template<typename Trans>
class Graph {
 public:
  explicit Graph();

  bool IsTerminal() const;
  std::string NextState(const Trans&) const;

  bool Step(const Trans&);
  bool AddState(const std::string&, bool terminal);
  bool DefineTransition(const std::string&, const std::string&, Trans);
  bool RemoveTransition(const std::string&, const Trans&);
  
  void Reset();
  
 private:
  struct State {
    State(std::string id, bool terminal)
        : kId(std::move(id)), kTerminal(terminal) {}

    const std::string kId;
    const bool kTerminal;
    std::unordered_map<Trans, std::string> trans_map;
  };

  std::unordered_map<std::string, State> states_;
  std::string curr_state_id_;
};

template<typename Trans>
Graph<Trans>::Graph() : curr_state_id_("") {
  AddState("", false);
}

template<typename Trans>
bool Graph<Trans>::IsTerminal() const {
  return states_.find(curr_state_id_)->second.kTerminal;
}

template<typename Trans>
std::string Graph<Trans>::NextState(const Trans& transition) const {
  auto state_it = states_.find(curr_state_id_);
  auto id_it = state_it->trans_map.find(transition);
  return (id_it == state_it->trans_map.end()) ? "" : id_it->second;
}

template<typename Trans>
bool Graph<Trans>::Step(const Trans& transition) {
  std::string next_id = NextState(transition);
  if (transition.empty()) return false;
  curr_state_id_ = std::move(next_id);
  return true;
}

template<typename Trans>
bool Graph<Trans>::AddState(const std::string& id, bool terminal) {
  if (states_.find(id) != states_.end()) return false;
  states_.emplace(std::piecewise_construct,
                  std::forward_as_tuple(id),
                  std::forward_as_tuple(id, terminal));
  return true;
}

template<typename Trans>
bool Graph<Trans>::DefineTransition(const std::string& src_id,
                                    const std::string& dst_id,
                                    Trans transition) {
  auto src_it = states_.find(src_id);
  if (src_it == states_.end()) return false;
  auto dst_it = states_.find(dst_id);
  if (dst_it == states_.end()) return false;
  
}

template<typename Trans>
bool Graph<Trans>::RemoveTransition(const std::string& id,
                                    const Trans& transition) {
  auto state_it = states_.find(id);
  if (state_it == states_.end()) return false;
  auto trans_it = state_it->trans_map.find(transition);
  if (trans_it == state_it->trans_map.end()) return false;
  state_it->trans_map.erase(trans_it);
  return true;
}

template<typename Trans>
void Graph<Trans>::Reset() {
  curr_state_id_ = "";
}

}  // namespace fsm
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_PARSER_FSM_GRAPH_H_
