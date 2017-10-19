#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v1;
  v1.push_back(5);
  v1.push_back(16);
  cout << "v1: " ;
  for (int x : v1)
    cout << x << " ";
  cout << endl;

  vector<int> v2 = {16, 3, 6, 1, 9, 10};
  cout << "v2: ";
  for (int x : v2)
    cout << x << " ";
  cout << endl;

  vector<int> v3{5, 2, 10, 1, 8};
  cout << "v3: ";
  for (int x : v3)
    cout << x << " ";
  cout << endl;

  vector<int> v4(5, 10);
  cout << "v4: ";
  for (int x : v4)
    cout << x << " ";
  cout << endl;

  vector<int> v5(v2);
  cout << "v5: ";
  for (int x : v5)
    cout << x << " ";
  cout << endl;

  vector<int> v6(v2.begin() + 1, v2.end() - 1);
  cout << "v6: ";
  for (int x : v6)
    cout << x << " ";
  cout << endl;
}