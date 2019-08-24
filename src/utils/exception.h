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

#ifndef CPPND_CAPSTONE_CALC_UTILS_EXCEPTION_H_
#define CPPND_CAPSTONE_CALC_UTILS_EXCEPTION_H_

#include <exception>
#include <string>
#include <utility>

namespace calc {
namespace utils {

class Exception : public std::exception {
 public:
  explicit Exception(std::string message)
      : message_(std::move(message)) {}
  
  const char* what() const noexcept override {
    return message_.c_str();
  }
 
 private:
  const std::string message_;
};

}  // namespace utils
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_UTILS_EXCEPTION_H_
