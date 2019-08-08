#ifndef CPPND_CAPSTONE_CALC_CORE_TOKENIZER_UTILS_H_
#define CPPND_CAPSTONE_CALC_CORE_TOKENIZER_UTILS_H_

#include <memory>
#include <string>
#include <vector>

#include "core/fsm/graph.h"

namespace calc {
namespace tokens {

std::unique_ptr<Graph<char>> CreateTokenizationGraph(
    const std::string& num_config_file,
    const std::vector<std::string>& symbols);

}  // namespace tokens
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_TOKENIZER_UTILS_H_
