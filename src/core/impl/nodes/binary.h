#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_BINARY_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_BINARY_H_

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

class BinaryOp : public Node {
 public:
  BinaryOp(Precedence, ::calc::lang::BinaryFn);

 private:
  virtual float ComputeValue() const;

  const ::calc::lang::BinaryFn func_;
};

}  // namespace nodes
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_BINARY_H_
