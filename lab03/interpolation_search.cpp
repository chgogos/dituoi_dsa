template <class T> int interpolation_search(T a[], int l, int r, T key) {
  int m;
  if (l > r) {
    return -1;
  } else if (l == r) {
    m = l;
  } else {
    double c = (double)(key - a[l]) / (double)(a[r] - a[l]);
    if ((c < 0) || (c > 1))
      return -1;
    m = (int)(l + (r - l) * c);
  }
  if (a[m] == key) {
    return m;
  } else if (key < a[m]) {
    return interpolation_search(a, l, m - 1, key);
  } else {
    return interpolation_search(a, m + 1, r, key);
  }
}

template <class T> int interpolation_search(T a[], int n, T key) {
  return interpolation_search(a, 0, n - 1, key);
}