#include <iostream>
using namespace std;

template <typename T> T min(T a, T b, T c) {
  T m = a;
  if (b < m)
    m = b;
  if (c < m)
    m = c;
  return m;
}

int main(int argc, char *argv[]) {
  cout << "The minimum among 3 integer numbers is " << min(5, 10, 7) << endl;
  cout << "The minimum among 3 real numbers is " << min(3.1, 0.7, 2.5) << endl;
}
