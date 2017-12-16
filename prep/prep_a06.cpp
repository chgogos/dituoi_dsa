#include <iostream>

using namespace std;

// insertion sort only for items at odd indexes
template <class T> void insertion_sort(T a[], int n) {
  for (int i = 1; i < n; i += 2) {
    T key = a[i];
    int j = i - 2;
    while ((j >= 0) && (key < a[j])) {
      a[j + 2] = a[j];
      j -= 2;
    }
    a[j + 2] = key;
  }
}

int main(void) {
  int a[] = {13, 25, 67, 77, 11, 90, 18, 22, 13, 12};
  insertion_sort(a, 10);
  for (int i = 0; i < 10; i++)
    cout << (i % 2 == 1 ? "*" : "") << "a[" << i << "]=" << a[i] << " ";
  cout << endl;
}