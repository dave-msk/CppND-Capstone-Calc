#ifndef CPPND_CAPSTONE_CALC_PARSER_NODES_NUMBER_H_
#define CPPND_CAPSTONE_CALC_PARSER_NODES_NUMBER_H_

#include "parser/nodes/node.h"
#include "parser/nodes/priority.h"

namespace calc {

class Number : public Node {
 public:
  Number(float value) : Node(Precedence::MAX), value_(value) {};

 private:
  float ComputeValue() { return value_; }

  float value_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_PARSER_NODES_NUMBER_H_