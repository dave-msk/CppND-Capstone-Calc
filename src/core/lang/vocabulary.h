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
