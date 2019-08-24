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
