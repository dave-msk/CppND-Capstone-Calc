#include "core/lang/vocabulary.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "core/lang/symbols.h"
#include "core/lang/syntax.h"

namespace {

using namespace ::calc::lang;

const std::unordered_map<char, SyntaxType> syntax_type_map = {
    {'P', SyntaxType::PREFIX},
    {'I', SyntaxType::INFIX},
    {'S', SyntaxType::SUFFIX},
    {'V', SyntaxType::VALUE},
    {'F', SyntaxType::FUNCTION},
    {'O', SyntaxType::OPEN},
    {'C', SyntaxType::CLOSE}
};

const std::vector<Element> vocabulary = {
    Element{"(", SyntaxType::OPEN, SymbolType(MiscType::OPEN_BRACKET)},
    Element{")", SyntaxType::CLOSE, SymbolType(MiscType::CLOSE_BRACKET)},
    Element{"+", SyntaxType::INFIX, SymbolType(BinaryOpType::ADD)},
    Element{"-", SyntaxType::INFIX, SymbolType(BinaryOpType::MINUS)},
    Element{"*", SyntaxType::INFIX, SymbolType(BinaryOpType::MULTIPLY)},
    Element{"/", SyntaxType::INFIX, SymbolType(BinaryOpType::DIVIDE)},
    Element{"+", SyntaxType::PREFIX, SymbolType(UnaryOpType::IDENTITY)},
    Element{"-", SyntaxType::PREFIX, SymbolType(UnaryOpType::NEGATE)},
    Element{"pi", SyntaxType::VALUE, SymbolType(Constant::PI)},
    Element{"e", SyntaxType::VALUE, SymbolType(Constant::E)},
    Element{"sin", SyntaxType::FUNCTION, SymbolType(UnaryOpType::SIN)},
    Element{"cos", SyntaxType::FUNCTION, SymbolType(UnaryOpType::COS)},
    Element{"tan", SyntaxType::FUNCTION, SymbolType(UnaryOpType::TAN)},
    Element{"sinh", SyntaxType::FUNCTION, SymbolType(UnaryOpType::SINH)},
    Element{"cosh", SyntaxType::FUNCTION, SymbolType(UnaryOpType::COSH)},
    Element{"tanh", SyntaxType::FUNCTION, SymbolType(UnaryOpType::TANH)}
};

}  // namespace

namespace calc {
namespace lang {

std::vector<Element> GetVocabulary() {
  return ::vocabulary;
}

std::unordered_map<char, SyntaxType> GetSyntaxTypeMap() {
  return ::syntax_type_map;
}

std::unordered_set<std::string> GetSymbols() {
  std::unordered_set<std::string> symbols;
  for (auto elem : ::vocabulary) symbols.emplace(elem.symbol);
  return symbols;
}

}  // namespace logic
}  // namespace calc
