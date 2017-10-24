template <class T> void insertion_sort(T a[], int n) {
  for (int i = 1; i < n; i++) {
    T key = a[i];
    int j = i - 1;
    while ((j >= 0) && (key < a[j])) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}