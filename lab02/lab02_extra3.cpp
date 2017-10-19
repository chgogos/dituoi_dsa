#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1{1, 2, 3, 4, 5, 6};
  vector<int> v2(6, 1);

  // capture by value
  auto lambda1 = [=](int x) {
    cout << "v1: ";
    for (auto p = v1.begin(); p != v1.end(); p++)
      if (*p != x)
        cout << *p << " ";
    cout << endl;
  };

  // capture by reference
  auto lambda2 = [&](int x) {
    for (auto p = v2.begin(); p != v2.end(); p++)
      (*p) += x;
  };

  // mixed capture
  auto lambda3 = [v1, &v2](int x) {
    cout << "v1: ";
    for (auto p = v1.begin(); p != v1.end(); p++)
      if (*p != x)
        cout << *p << " ";
    cout << endl;
    for (auto p = v2.begin(); p != v2.end(); p++)
      (*p) += x;
  };

  lambda1(1);
  lambda2(1);
  lambda3(1);

  cout << "v2: ";
  for (int x : v2)
    cout << x << " ";
  cout << endl;
}