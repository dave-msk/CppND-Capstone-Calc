#ifndef CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_PREFIX_H_
#define CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_PREFIX_H_

#include "parser/nodes/node.h"
#include "parser/nodes/priority.h"

namespace calc {

class PrefixOp : public Node {
 public:
  using UnaryFn = float (*)(float);

  PrefixOp(Precedence, UnaryFn);

 private:
  virtual float ComputeValue();

  const UnaryFn func_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_PREFIX_H_