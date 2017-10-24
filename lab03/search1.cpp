#include <iostream>

using namespace std;

template <class T> int sequential_search(T a[], int n, T key) {
  for (int i = 0; i < n; i++)
    if (a[i] == key)
      return i;
  return -1;
}

int main(int argc, char **argv) {
  int a[] = {5, 11, 45, 23, 10, 17, 32, 8, 9, 4};
  int key;
  cout << "Search for: ";
  cin >> key;
  int pos = sequential_search(a, 10, key);
  if (pos == -1)
    cout << "Not found" << endl;
  else
    cout << "Found at position " << pos << endl;
}
