#include "core/nodes/numbers/registry.h"

#include <cmath>
#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/numbers/number.h"
#include "core/nodes/numbers/type.h"

namespace calc {
namespace nodes {

std::unique_ptr<Node> CreateNode(Constant constant) {
  float value;
  switch (constant) {
    case Constant::E: {
      value = M_E;
    }
    case Constant::PI: {
      value = M_PI;
    }
  }

  return CreateNode(value);
}

std::unique_ptr<Node> CreateNode(const Literal& literal) {
  return std::unique_ptr<Node>(new Number(literal.value));
}

}  // namespace nodes
}  // namespace calc
