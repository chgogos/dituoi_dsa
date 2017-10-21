#include <cstdio>

void simple_stats(int a[], int N, double *avg, int *min, int *max) {
  int sum;
  sum = *min = *max = a[0];
  for (int i = 1; i < N; i++) {
    sum += a[i];
    if (*max < a[i])
      *max = a[i];
    if (*min > a[i])
      *min = a[i];
  }
  *avg = (double)sum / (double)N;
}

int main(int argc, char **argv) {
  int a[] = {3, 2, 9, 5, 1};
  double avg;
  int min, max;
  simple_stats(a, 5, &avg, &min, &max);
  printf("Average= %.2f min=%d max=%d\n", avg, min, max);
  return 0;
}
