template <class T> void merge(T a[], int l, int m, int r) {
  T la[m - l + 1];
  T ra[r - m];
  for (int i = 0; i < m - l + 1; i++)
    la[i] = a[l + i];
  for (int i = 0; i < r - m; i++)
    ra[i] = a[m + 1 + i];
  int i = 0, j = 0, k = l;
  while ((i < m - l + 1) && (j < r - m)) {
    if (la[i] < ra[j]) {
      a[k] = la[i];
      i++;
    } else {
      a[k] = ra[j];
      j++;
    }
    k++;
  }
  if (i == m - l + 1) {
    while (j < r - m) {
      a[k] = ra[j];
      j++;
      k++;
    }
  } else {
    while (i < m - l + 1) {
      a[k] = la[i];
      i++;
      k++;
    }
  }
}

template <class T> void merge_sort(T a[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

template <class T> void merge_sort(T a[], int N) { merge_sort(a, 0, N - 1); }
