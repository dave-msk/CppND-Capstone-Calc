#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_NUMBER_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_NUMBER_H_

#include "core/nodes/node.h"
#include "core/nodes/priority.h"

namespace calc {

class Number : public Node {
 public:
  Number(float value) : Node(Precedence::MAX), value_(value) {};

 private:
  virtual float ComputeValue() { return value_; }

  float value_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_NUMBER_H_
