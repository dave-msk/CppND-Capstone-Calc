/* Copyright 2019 Siu-Kei Muk (David). All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "core/lang/binaryfn.h"

#include <cmath>

namespace calc {
namespace lang {
namespace unaryfn {

float Identity(float v) {
  return v;
}

float Negate(float v) {
  return -v;
}

float Sin(float v) {
  return std::sin(v);
}

float Cos(float v) {
  return std::cos(v);
}

float Tan(float v) {
  return std::tan(v);
}

float Sinh(float v) {
  return std::sinh(v);
}

float Cosh(float v) {
  return std::cosh(v);
}

float Tanh(float v) {
  return std::tanh(v);
}

}  // namespace unaryfn
}  // namespace lang
}  // namespace calc
