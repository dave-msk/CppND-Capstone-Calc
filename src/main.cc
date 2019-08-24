#include <memory>
#include <vector>

#include "cxxopts.hpp"

#include "core/calculator.h"
#include "core/impl/parser/factories.h"
#include "core/impl/parser/parser.h"
#include "core/impl/parser/tokenizer.h"
#include "core/lang/vocabulary.h"
#include "ui/shell.h"

cxxopts::Options GetOptions() {
  cxxopts::Options options(
    "Calculator",
    "Simple calculator program for Udacity CPPND Capstone Project.");
  options.add_options()
      ("n,num_config",
       "Configuration file (in YAML) for numeral parsing.",
       cxxopts::value<std::string>()->default_value("data/numerals.yaml"))
      ("g,grammar_config",
       "Configuration file (in YAML) for grammar parsing.",
       cxxopts::value<std::string>()->default_value("data/grammar.yaml"));
  return options;
}


int main(int argc, char** argv) {
  cxxopts::Options opt = GetOptions();
  auto flags = opt.parse(argc, argv);

  const std::string num_config = flags["num_config"].as<std::string>();
  const std::string grammar_config = flags["grammar_config"].as<std::string>();

  auto tokenizer = calc::impl::parser::CreateTokenizer(
      calc::impl::parser::CreateTokenizationGraph(
          num_config, calc::lang::GetSymbols()));
  auto parser = calc::impl::parser::CreateParser(
      calc::impl::parser::CreateGrammarGraph(grammar_config,
                                             calc::lang::GetSyntaxTypeMap()),
      calc::lang::GetVocabulary());
    
  auto calculator = std::make_unique<calc::Calculator>(std::move(tokenizer),
                                                       std::move(parser));
  
  auto ui = std::make_unique<calc::Shell>();
  ui->Launch([&](std::string s) { return calculator->Compute(s); });

  return 0;
}
