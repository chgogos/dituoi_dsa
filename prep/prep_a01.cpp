#include <cmath>
#include <iostream>

using namespace std;

void func1(int a[], int N, double x, int &c, double &sum) {
  c = 0;
  sum = 0.0;
  for (int i = 0; i < N; i++) {
    if (a[i] > x)
      c++;
    sum += fabs(x - a[i]);
    }
}

int main(void) {
  int a[] = {4, 5, 7, 9, 10, 11, 8, 6};
  int c;
  double sum, x = 5.5;
  func1(a, 8, x, c, sum);
  cout << "Results " << c << " " << sum << endl;
}