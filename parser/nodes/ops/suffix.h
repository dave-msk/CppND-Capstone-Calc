#ifndef CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_SUFFIX_H_
#define CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_SUFFIX_H_

#include "parser/nodes/node.h"
#include "parser/nodes/priority.h"

namespace calc {

class SuffixOp : public Node {
 public:
  using UnaryFn = float (*)(float);

  SuffixOp(Precedence, UnaryFn);

 private:
  virtual float CompuateValue();

  const UnaryFn func_;
};

}

#endif  // CPPND_CAPSTONE_CALC_PARSER_NODES_OPS_SUFFIX_H_
