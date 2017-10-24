#include <utility> // std::swap

template <class T> int partition(T a[], int l, int r) {
  int p = l;
  int i = l + 1;
  for (int j = l + 1; j <= r; j++) {
    if (a[j] < a[p]) {
      std::swap(a[j], a[i]);
      i++;
    }
  }
  std::swap(a[p], a[i - 1]);
  return i - 1;
}

template <class T> void quick_sort(T a[], int l, int r) {
  if (l >= r)
    return;
  else {
    int p = partition(a, l, r);
    quick_sort(a, l, p - 1);
    quick_sort(a, p + 1, r);
  }
}

template <class T> void quick_sort(T a[], int N) { quick_sort(a, 0, N - 1); }