#include <iostream>
using namespace std;

int min(int a, int b, int c) {
  int m = a;
  if (b < m)
    m = b;
  if (c < m)
    m = c;
  return m;
}

double min(double a, double b, double c) {
  double m = a;
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
