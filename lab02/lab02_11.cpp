#include <array>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  vector<int> v{5, 15, 20, 17, 11, 9};
  int sum = accumulate(v.begin(), v.end(), 0);
  cout << "Sum over vector using accumulate: " << sum << endl;

  array<int, 6> a{5, 15, 20, 17, 11, 9};
  sum = accumulate(a.begin(), a.end(), 0);
  cout << "Sum over array using accumulate: " << sum << endl;
}