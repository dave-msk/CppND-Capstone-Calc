#include <iostream>

#include <memory>
#include <sstream>
#include <vector>

#include "core/impl/parser/factories.h"
#include "core/impl/parser/parser.h"
#include "core/impl/parser/tokenizer.h"
#include "core/lang/vocabulary.h"
#include "ui/shell.h"

int main() {

  const std::string num_graph_config = "data/numerals.yaml";
  const std::string grammar_graph_config = "data/grammar.yaml";
  // std::vector<std::string> v{"+", "-", "*", "/", "(", ")",
  //                            "e", "pi",
  //                            "sin", "sinh", "cos", "cosh", "tan", "tanh"};

  // std::cout << "Line 1" << std::endl;

  // auto graph = calc::fsm::CreateTokenizationGraph(filename, v.begin(), v.end());
  // graph->PrintState("");
  // graph->PrintState("numeral/s1");

  auto tokenizer = calc::impl::parser::CreateTokenizer(
      calc::impl::parser::CreateTokenizationGraph(
          num_graph_config, calc::lang::GetSymbols()));
  auto parser = calc::impl::parser::CreateParser(
      calc::impl::parser::CreateGrammarGraph(grammar_graph_config,
                                             calc::lang::GetSyntaxTypeMap()),
      calc::lang::GetVocabulary());
  
  // auto ui = std::make_unique<calc::Shell>();
  //   ui->Launch([&](std::string s) {
  //     auto tokens = tokenizer.Tokenize(s);
  //     auto node = parser.Parse(tokens);
  //     float result = node->GetValue();
  //     return std::to_string(result);
  //   });
  // ui->Launch([&](std::string s) {
  //   std::vector<std::string> tokens = tokenizer.Tokenize(s);
  //   std::ostringstream oss;
  //   for (auto t : tokens) {
  //     oss << t << " ";
  //   }
  //   return oss.str();
  // });
  
  
  // std::cout << "Line 2" << std::endl;
  
  std::string test_str = ".368*sin(pi/3) - 4. / cosh(pi/4)";
  std::vector<std::string> tokens = tokenizer->Tokenize(test_str);

  std::cout << "Line 3" << std::endl;

  auto expr = parser->Parse(tokens);

  std::cout << "Line 4" << std::endl;

  std::cout << expr->GetValue() << std::endl;


  // for (auto token : result) {
  //   std::cout << token << " ";
  // }
  // std::cout << std::endl;
  
  return 0;
}