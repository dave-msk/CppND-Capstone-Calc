#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_UNARY_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_UNARY_H_

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

class UnaryOp : public Node {
 public:
  UnaryOp(Precedence, bool, ::calc::lang::UnaryFn);

 protected:
  const bool prefix_op_;
  const ::calc::lang::UnaryFn func_;

 private:
  virtual float ComputeValue() const;
};

class FunctionOp : public UnaryOp {
 public:
  FunctionOp(::calc::lang::UnaryFn);

 private:
  virtual bool IsValidParent(const Node&) const { return true; }
};

}  // namespace nodes
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_UNARY_H_