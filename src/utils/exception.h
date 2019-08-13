#ifndef CPPND_CAPSTONE_CALC_UTILS_EXCEPTION_H_
#define CPPND_CAPSTONE_CALC_UTILS_EXCEPTION_H_

#include <exception>
#include <string>
#include <utility>

namespace calc {
namespace utils {

class Exception : public std::exception {
 public:
  explicit Exception(std::string message)
      : message_(std::move(message)) {}
  
  const char* what() const noexcept override {
    return message_.c_str();
  }
 
 private:
  const std::string message_;
};

}  // namespace utils
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_UTILS_EXCEPTION_H_
