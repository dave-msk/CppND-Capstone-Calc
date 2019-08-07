#include <iostream>

#include <memory>
#include <sstream>
#include <vector>

#include "core/fsm/factories.h"
#include "core/tokenizer.h"
#include "ui/shell.h"

int main() {

  std::string filename = "data/numerals.yaml";
  std::vector<std::string> v{"+", "-", "*", "/", "(", ")",
                             "e", "pi",
                             "sin", "sinh", "cos", "cosh", "tan", "tanh"};

  // std::cout << "Line 1" << std::endl;

  // auto graph = calc::fsm::CreateTokenizationGraph(filename, v.begin(), v.end());
  // graph->PrintState("");
  // graph->PrintState("numeral/s1");

  calc::Tokenizer tokenizer = calc::Tokenizer(
      calc::fsm::CreateTokenizationGraph(filename, v.begin(), v.end()));
  
  auto ui = std::make_unique<calc::Shell>();
    ui->Launch([&](std::string s) {
      std::vector<std::string> tokens = tokenizer.Tokenize(s);
      std::ostringstream oss;
      for (auto t : tokens) {
        oss << t << " ";
      }
      return oss.str();
    });
  // ui->Launch([&](std::string s) {
  //   std::vector<std::string> tokens = tokenizer.Tokenize(s);
  //   std::ostringstream oss;
  //   for (auto t : tokens) {
  //     oss << t << " ";
  //   }
  //   return oss.str();
  // });
  
  
  // std::cout << "Line 2" << std::endl;
  
  // std::string test_str = ".368*sin(24.7) - 4. / cosh(52.1)";

  // std::vector<std::string> result = tokenizer.Tokenize(test_str);

  // std::cout << "Line 3" << std::endl;

  // for (auto token : result) {
  //   std::cout << token << " ";
  // }
  // std::cout << std::endl;
  
  return 0;
}