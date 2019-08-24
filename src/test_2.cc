#include <iostream>
#include <cstddef>
#include <cmath>

enum class Constant : std::size_t {
  ONE = 1,
  TWO = 2
};

int main() {
  std::cout << std::log(2) << std::endl;

  return 0;
}