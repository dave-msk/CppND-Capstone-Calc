#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_TYPE_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_NUMBERS_TYPE_H_

namespace calc {
namespace nodes {

enum class Constant {
  E,
  PI
};

struct Literal {
  explicit Literal(float value) : value(value) {}
  float value;
};

}  // namespace nodes
}  // namespace calc
