#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
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

  cout << "Example1: capture by value (all external variables)" << endl;
  lambda1(1);
  cout << "Example2: capture by reference (all external variables)" << endl;
  lambda2(2);
  cout << "Example3: mixed capture (v1 by value, v2 by reference)" << endl;
  lambda3(1);

  cout << "v1: ";
  for (int x : v1)
    cout << x << " ";
  cout << endl;

  cout << "v2: ";
  for (int x : v2)
    cout << x << " ";
  cout << endl;
}