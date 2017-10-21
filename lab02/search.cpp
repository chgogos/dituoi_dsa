#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int a[] = {45, 32, 16, 11, 7, 18, 21, 16, 11, 15};
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
    cout << "found" << endl;
  else
    cout << "not found" << endl;

  auto it = lower_bound(a, a + N, key);
  if (*it == key)
    cout << "found at position " << it - a << endl;
  else
    cout << "not found" << endl;
}
