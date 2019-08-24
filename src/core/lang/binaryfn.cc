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
namespace binaryfn {

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

}  // namespace binaryfn
}  // namespace lang
}  // namespace calc
