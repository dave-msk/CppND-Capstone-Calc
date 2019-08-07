#ifndef CPPND_CAPSTONE_CALC_CORE_PriorityS_PRECEDENCE_H_
#define CPPND_CAPSTONE_CALC_CORE_PriorityS_PRECEDENCE_H_

#include <cstddef>

namespace calc {

enum class Precedence : std::size_t {
  ONE = 1,
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  SIX = 6,
  MAX = 999
};

class Priority {
 public:
  Priority(Precedence precedence);

  ~Priority() = default;
  
  friend bool operator==(const Priority&, const Priority&);
  friend bool operator!=(const Priority&, const Priority&);
  friend bool operator<(const Priority&, const Priority&);
  friend bool operator>(const Priority&, const Priority&);
  friend bool operator<=(const Priority&, const Priority&);
  friend bool operator>=(const Priority&, const Priority&);

 private:
  static std::size_t inst_count_ = 0;
  
  const std::size_t index_;
  const std::size_t precedence_;
  bool left_associative_;
};

}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_PriorityS_PRECEDENCE_H_
