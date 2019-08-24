# Copyright 2019 Siu-Kei Muk (David). All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

# cmake version to be used
cmake_minimum_required( VERSION 3.12 )

# project name
project( calc )

# flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# files
file(COPY ./data DESTINATION ${CMAKE_BINARY_DIR})

# packages
find_package( yaml-cpp REQUIRED )
find_package( cxxopts REQUIRED )

#include
include_directories( ./src )

# target
add_executable(
  calc
  ./src/core/calculator.cc
  ./src/core/impl/nodes/binary.cc
  ./src/core/impl/nodes/factories.cc
  ./src/core/impl/nodes/misc.cc
  ./src/core/impl/nodes/node.cc
  ./src/core/impl/nodes/number.cc
  ./src/core/impl/nodes/priority.cc
  ./src/core/impl/nodes/unary.cc
  ./src/core/impl/parser/factories.cc
  ./src/core/impl/parser/parser.cc
  ./src/core/impl/parser/tokenizer.cc
  ./src/core/lang/binaryfn.cc
  ./src/core/lang/logic.cc
  ./src/core/lang/unaryfn.cc
  ./src/core/lang/vocabulary.cc
  ./src/main.cc
  ./src/ui/shell.cc
)

# external libs
target_link_libraries(calc yaml-cpp)
