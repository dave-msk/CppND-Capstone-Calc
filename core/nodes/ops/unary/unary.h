#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_UNARY_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_UNARY_H_

#include "core/nodes/node.h"
#include "core/nodes/priority.h"

namespace calc {
namespace nodes {

class UnaryOp : public Node {
 public:
  using UnaryFn = float (*)(float);

  UnaryOp(Precedence, bool, UnaryFn);

 protected:
  const bool prefix_op_;
  const UnaryFn func_;

 private:
  virtual float ComputeValue();
};

class FunctionOp : public UnaryOp {
 public:
  FunctionOp(UnaryFn);

 private:
  virtual bool IsValidParent(const Node&) const { return true; }
}

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OPS_UNARY_UNARY_H_