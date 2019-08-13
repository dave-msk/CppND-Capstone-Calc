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
