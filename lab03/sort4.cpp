#include <iostream>
#include <utility> // swap

using namespace std;

template <class T> void rank_sort(T a[], int n) {
  int r[n] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[j] < a[i] || (a[j] == a[i] && j < i))
        r[i]++;
  int temp[n];
  for (int i = 0; i < n; i++)
    temp[r[i]] = a[i];
  for (int i = 0; i < n; i++)
    a[i] = temp[i];
}

template <class T> void rank_sort_in_place(T a[], int n) {
  int r[n] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (a[j] <= a[i])
        r[i]++;
      else
        r[j]++;
  for (int i = 0; i < n; i++)
    while (r[i] != i) {
      int t = r[i];
      swap(a[i], a[t]);
      swap(r[i], r[t]);
    }
}

int main(int argc, char **argv) {
  int a[] = {45, 32, 16, 11, 7, 18, 21, 16, 11, 15};
  cout << "Sort using rank sort" << endl;
  rank_sort(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl << "Sort using rank sort (in place)" << endl;
  int b[] = {45, 32, 16, 11, 7, 18, 21, 16, 11, 15};
  rank_sort_in_place(b, 10);
  for (int i = 0; i < 10; i++)
    cout << b[i] << " ";
}
