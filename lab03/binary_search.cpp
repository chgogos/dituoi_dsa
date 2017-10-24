template <class T> int binary_search(T a[], int l, int r, T key) {
  int m = (l + r) / 2;
  if (l > r) {
    return -1;
  } else if (a[m] == key) {
    return m;
  } else if (key < a[m]) {
    return binary_search(a, l, m - 1, key);
  } else {
    return binary_search(a, m + 1, r, key);
  }
}

template <class T> int binary_search(T a[], int n, T key) {
  return binary_search(a, 0, n - 1, key);
}