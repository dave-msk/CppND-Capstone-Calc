# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( calc )

# flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# packages
find_package( yaml-cpp REQUIRED )

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
  ./src/core/lang/logic.cc
  ./src/core/lang/vocabulary.cc
  ./src/main.cc
  ./src/ui/shell.cc
)

# external libs
target_link_libraries( calc yaml-cpp)