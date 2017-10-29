#include <algorithm>
#include <iostream>

using namespace std;

bool first_element_even(int a[]) { return a[0] % 2 == 0; }

bool exists(int a[], int N, int key) {
  for (int i = 0; i < N; i++)
    if (a[i] == key)
      return true;
  return false;
}

bool has_duplicates(int a[], int N) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;
      if (a[i] == a[j])
        return true;
    }
  return false;
}

int fibo(int n) {
  if (n <= 1)
    return n;
  else
    return fibo(n - 2) + fibo(n - 1);
}

bool exists_in_sorted(int a[], int N, int key) {
  int left = 0, right = N - 1, m;
  while (left <= right) {
    m = (left + right) / 2;
    if (a[m] == key)
      return true;
    else if (a[m] > key)
      right = m - 1;
    else
      left = m + 1;
  }
  return false;
}

int main(void) {
  constexpr int N = 10;
  int a[N] = {21, 34, 12, 67, 78, 23, 27, 90, 11, 79};
  int key = 200;

  // Ο(1)
  bool b = first_element_even(a);
  cout << "The first element is " << (b ? "even" : "odd") << endl;

  // O(N)
  b = exists(a, N, key);
  cout << (b ? "Key found" : "Key not found") << endl;

  // O(N^2)
  b = has_duplicates(a, N);
  cout << (b ? "Duplicates exist" : "Duplicates don't exist") << endl;

  // O(2^N)
  cout << "Fibonacci number " << fibo(10) << endl;

  sort(a, a + N);
  // O(log(N))
  b = exists_in_sorted(a, N, key);
  cout << (b ? "Key found" : "Key not found") << endl;
}