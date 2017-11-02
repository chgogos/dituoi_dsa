#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  vector<int> a = {45, 11, 16, 11, 7, 18, 21, 16, 11, 15};
  cout << "The size of the vector is " << a.size() << endl;
  int key;
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << " ";
  cout << endl;
  cout << "Enter a value to be searched for: ";
  cin >> key;
  if (binary_search(a.begin(), a.end(), key))
    cout << "Found using binary_search" << endl;
  else
    cout << "Not found (binary_search)" << endl;

  auto it1 = lower_bound(a.begin(), a.end(), key);
  auto it2 = upper_bound(a.begin(), a.end(), key);
  if (*it1 == key) {
    cout << "Found at positions " << it1 - a.begin() << " up to "
         << it2 - a.begin() - 1 << endl;
  } else
    cout << "Not found (lower_bound and upper_bound)" << endl;
}
