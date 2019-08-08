#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_TYPE_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_TYPE_H_

namespace calc {
namespace nodes {

enum class UnaryOpType {
  NEGATE,
  IDENTITY,
  SIN,
  COS,
  TAN,
  SINH,
  COSH,
  TANH
};

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_TYPE_H_
