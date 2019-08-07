#ifndef CPPND_CAPSTONE_CALC_CORE_FSM_FACTORIES_H_
#define CPPND_CAPSTONE_CALC_CORE_FSM_FACTORIES_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "core/fsm/graph.h"

namespace calc {
namespace fsm {

std::unique_ptr<Graph<char>> CreateTokenizationGraph(
    const std::string& num_config_file,
    const std::vector<std::string>& symbols);

std::unique_ptr<Graph<

}  // namespace fsm
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_FSM_FACTORIES_H_
