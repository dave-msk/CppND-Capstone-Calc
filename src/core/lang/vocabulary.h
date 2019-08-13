#ifndef CPPND_CAPSTONE_CALC_CORE_LANG_VOCABULARY_H_
#define CPPND_CAPSTONE_CALC_CORE_LANG_VOCABULARY_H_

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "core/lang/symbols.h"
#include "core/lang/syntax.h"

namespace calc {
namespace lang {

std::vector<Element> GetVocabulary();
std::unordered_map<char, SyntaxType> GetSyntaxTypeMap();
std::unordered_set<std::string> GetSymbols();

}  // namespace lang
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_LANG_VOCABULARY_H_
