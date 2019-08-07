#include "core/nodes/ops/binary/functions.h"

#include <cmath>

namespace calc {

float Add(float l, float r) {
  return l + r;
}

float Minus(float l, float r) {
  return l - r;
}

float Multiply(float l, float r) {
  return l * r;
}

float Divide(float l, float r) {
  return l / r;
}

float Power(float l, float r) {
  return std::pow(l, r);
}

}  // namespace calc
