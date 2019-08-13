#ifndef CPPND_CAPSTONE_CALC_CORE_EXCEPTION_H_
#define CPPND_CAPSTONE_CALC_CORE_EXCEPTION_H_

#include "utils/exception.h"

namespace calc {

class InvalidToken : public utils::Exception {
 public:
  using utils::Exception::Exception;
};

class InvalidSyntax : public utils::Exception {
 public:
  using utils::Exception::Exception;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_EXCEPTION_H_