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

#ifndef CPPND_CAPSTONE_CALC_CORE_LANG_UNARYFN_H_
#define CPPND_CAPSTONE_CALC_CORE_LANG_UNARYFN_H_

namespace calc {
namespace lang {
namespace unaryfn {

float Identity(float);
float Negate(float);
float Sin(float);
float Cos(float);
float Tan(float);
float Sinh(float);
float Cosh(float);
float Tanh(float);

}  // namespace unaryfn
}  // namespace lang
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_LANG_UNARYFN_H_

