#ifndef CPPND_CAPSTONE_CALC_UI_SHELL_H_
#define CPPND_CAPSTONE_CALC_UI_SHELL_H_

#include "ui/base_ui.h"

namespace calc {

class Shell : public BaseUI {
 public:
  using StringFunction = BaseUI::StringFunction;

  void Launch(StringFunction);
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_UI_SHELL_H_