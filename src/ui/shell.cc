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

#include "ui/shell.h"

#include <iostream>
#include <string>

namespace calc {

void Shell::Launch(Shell::StringFunction str_fn) {
  std::string input;
  while (true) {
    std::cout << ">> ";
    std::getline(std::cin, input);
    try {
      std::string output = str_fn(input);
      if (!output.empty()) {
        std::cout << output << std::endl;
      }
    } catch (...) {
      std::cerr << "Invalid input: " << input << std::endl;
    }
  }
}

}  // namespace calc
