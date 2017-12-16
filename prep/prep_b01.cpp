#include <iostream>

template <class T> void fun(T a[], int n, int pos, T x) {
  if (pos < 0 || pos >= n)
    return;
  for (int i = n - 1; i > pos; i--)
    a[i] = a[i - 1];
  a[pos] = x;
}

int main() {
  int a[] = {3,7,16,2,8,9};
  fun(a, 6, 2, 21);
  for (int i = 0; i < 6; i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;
}