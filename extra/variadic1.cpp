#include <iostream>

template <typename T> T adder(T v) { return v; }

template <typename T, typename... Args> T adder(T first, Args... args) {
  return first + adder(args...);
}

int main(void) {
  long sum = adder(1, 2, 3, 4, 5);
  std::cout << "The sum is " << sum << std::endl;
}