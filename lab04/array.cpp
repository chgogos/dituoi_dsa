#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int main() {
  array<double, 5> a{6.5, 2.1, 7.2, 8.1, 1.9};
  sort(a.begin(), a.end());
  for (double x : a)
    cout << x << " ";
  cout << endl;
}