#ifndef CPPND_CAPSTONE_CALC_UI_BASE_UI_H_
#define CPPND_CAPSTONE_CALC_UI_BASE_UI_H_

#include <functional>
#include <string>

namespace calc {

class BaseUI {
 public:
  using StringFunction = std::function<std::string(std::string)>;
  
  virtual ~BaseUI() {}
  virtual void Launch(StringFunction) = 0;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_UI_UI_H_
