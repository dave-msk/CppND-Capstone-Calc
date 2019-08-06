#ifndef CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_BINARY_BINARY_H_
#define CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_BINARY_BINARY_H_

#include "parser/nodes/node.h"
#include "parser/nodes/priority.h"

namespace calc {

class BinaryOp : public Node {
 public:
  using BinaryFn = float (*)(float, float);
  
  BinaryOp(Precedence, BinaryFn);

 private:
  virtual float ComputeValue();

  const BinaryFn func_;
}

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_BINARY_H_
