#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> v{3, 2, 8, 7, 4, 5};

  // find_if
  vector<int>::iterator iter = find_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
  cout << *iter << endl;

  // count_if
  int c = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
  cout << c << endl;


}