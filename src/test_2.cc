#include <iostream>
#include <cstddef>

enum class Constant : std::size_t {
  ONE = 1,
  TWO = 2
};

int main() {
  std::cout << (Constant::ONE < Constant::TWO) << std::endl;
  std::cout << (Constant::TWO < Constant::ONE) << std::endl;
  std::cout << (Constant::ONE == Constant::ONE) << std::endl;

  return 0;
}