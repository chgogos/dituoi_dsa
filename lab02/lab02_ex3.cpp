#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<string> v{"petros", "anna", "nikos"};
  sort(v.begin(), v.end());
  do {
    for (string x : v)
      cout << x << " ";
    cout << endl;
  } while (next_permutation(v.begin(), v.end()));
}