#include "core/nodes/ops/unary/functions.h"

#include <cmath>

namespace calc {
namespace unaryfn {

float Negate(float value) {
  return -value;
}

float Identity(float value) {
  return value;
}

float Sin(float value) {
  return std::sin(value);
}

float Cos(float value) {
  return std::cos(value);
}

float Tanh(float value) {
  return std::tan(value);
}

float Sinh(float value) {
  return std::sinh(value);
}

float Cosh(float value) {
  return std::cosh(value);
}

float Tanh(float value) {
  return std::tanh(value);
}

}  // namespace unaryfn
}  // namespace calc
