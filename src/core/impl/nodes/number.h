#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NUMBER_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NUMBER_H_

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

class Number : public Node {
 public:
  Number(float value) : Node(Precedence::MAX), value_(value) {};

 private:
  virtual float ComputeValue() const;

  const float value_;
};

}  // namespace nodes
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_NUMBER_H_
