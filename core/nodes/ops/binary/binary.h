#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_BINARY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_BINARY_H_

#include "core/nodes/node.h"
#include "core/nodes/priority.h"

namespace calc {
namespace nodes {

class BinaryOp : public Node {
 public:
  using BinaryFn = float (*)(float, float);
  
  BinaryOp(Precedence, BinaryFn);

 private:
  virtual float ComputeValue();

  const BinaryFn func_;
}

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OPS_BINARY_H_
