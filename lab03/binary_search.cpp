// non-recursive implementation
template <class T> int binary_search(T a[], int l, int r, T key) {
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m] == key)
      return m;
    else if (a[m] < key)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

template <class T> int binary_search(T a[], int n, T key) {
  return binary_search(a, 0, n - 1, key);
}

// recursive implementation
template <class T> int binary_search_r(T a[], int l, int r, T key) {
  int m = (l + r) / 2;
  if (l > r) {
    return -1;
  } else if (a[m] == key) {
    return m;
  } else if (key < a[m]) {
    return binary_search_r(a, l, m - 1, key);
  } else {
    return binary_search_r(a, m + 1, r, key);
  }
}

template <class T> int binary_search_r(T a[], int n, T key) {
  return binary_search_r(a, 0, n - 1, key);
}