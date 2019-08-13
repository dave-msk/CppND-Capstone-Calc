#ifndef CPPND_CAPSTONE_CALC_CORE_LANG_LOGIC_H_
#define CPPND_CAPSTONE_CALC_CORE_LANG_LOGIC_H_

#include "core/lang/symbols.h"

namespace calc {
namespace lang {

BinaryFn GetBinaryFn(BinaryOpType);
UnaryFn GetUnaryFn(UnaryOpType);
Literal GetConstant(Constant);

}  // namespace lang
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_LANG_LOGIC_H_
