#include <stdio.h>

void sums_row_wise(int a[][4], int M, int N, int *row) {
  for (int i = 0; i < M; i++) {
    row[i] = 0;
    for (int j = 0; j < N; j++)
      row[i] += a[i][j];
  }
}

int main(int argc, char **argv) {
  int a[5][4] = {{5, 4, 0, -1},
                 {1, 5, 42, 2},
                 {-3, 7, 8, 2},
                 {7, 312, -56, 6},
                 {19, 45, 6, 5}};
  int row[5];
  sums_row_wise(a, 5, 4, row);
  for (int i = 0; i < 5; i++)
    printf("sum of row %d is %d\n", i, row[i]);
  return 0;
}
