#include "core/nodes/numbers/registry.h"

#include <cmath>
#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/numbers/number.h"

namespace calc {

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

std::unique_ptr<Node> CreateNode(float value) {
  return std::unique_ptr<Node>(new Number(value));
}

}  // namespace calc
