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

#ifndef CPPND_CAPSTONE_CALC_UI_BASE_UI_H_
#define CPPND_CAPSTONE_CALC_UI_BASE_UI_H_

#include <functional>
#include <string>

namespace calc {

class BaseUI {
 public:
  using StringFunction = std::function<std::string(std::string)>;
  
  virtual ~BaseUI() {}
  virtual void Launch(StringFunction) = 0;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_UI_UI_H_
