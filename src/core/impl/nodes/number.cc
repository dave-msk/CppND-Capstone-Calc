#include "core/impl/nodes/number.h"

#include <cmath>
#include <memory>

#include "core/impl/nodes/node.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

float Number::ComputeValue() const {
  return value_;
}

}  // namespace nodes
}  // namespace impl
}  // namespace calc
