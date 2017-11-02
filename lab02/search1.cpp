#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int a[] = {45, 11, 16, 11, 7, 18, 21, 16, 11, 15};
  int N = sizeof(a) / sizeof(int);
  cout << "The size of the array is " << N << endl;
  int key;
  sort(a, a + N);
  for (int i = 0; i < N; i++)
    cout << a[i] << " ";
  cout << endl;
  cout << "Enter a value to be searched for: ";
  cin >> key;
  if (binary_search(a, a + N, key))
    cout << "Found using binary_search" << endl;
  else
    cout << "Not found (binary_search)" << endl;

  auto it1 = lower_bound(a, a + N, key);
  auto it2 = upper_bound(a, a + N, key);
  if (*it1 == key) {
    cout << "Found at positions " << it1 - a << " up to " << it2 - a - 1
         << endl;
  } else
    cout << "Not found (lower_bound and upper_bound)" << endl;
}
