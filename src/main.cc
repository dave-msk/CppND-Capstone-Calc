#include <memory>
#include <sstream>
#include <vector>

#include "core/calculator.h"
#include "core/impl/parser/factories.h"
#include "core/impl/parser/parser.h"
#include "core/impl/parser/tokenizer.h"
#include "core/lang/vocabulary.h"
#include "ui/shell.h"

int main() {
  const std::string num_graph_config = "data/numerals.yaml";
  const std::string grammar_graph_config = "data/grammar.yaml";

  auto tokenizer = calc::impl::parser::CreateTokenizer(
      calc::impl::parser::CreateTokenizationGraph(
          num_graph_config, calc::lang::GetSymbols()));
  auto parser = calc::impl::parser::CreateParser(
      calc::impl::parser::CreateGrammarGraph(grammar_graph_config,
                                             calc::lang::GetSyntaxTypeMap()),
      calc::lang::GetVocabulary());
    
  auto calculator = std::make_unique<calc::Calculator>(std::move(tokenizer),
                                                       std::move(parser));
  
  auto ui = std::make_unique<calc::Shell>();
  ui->Launch([&](std::string s) { return calculator->Compute(s); });

  return 0;
}