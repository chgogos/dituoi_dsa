#include <stdio.h>

int main(int argc, char **argv) {
  double a[] = {3.2, 4.1, 7.3};
  double b[] = {6.0, .1, -5.3};
  double sum = .0;
  for (int i = 0; i < 3; i++)
    sum += a[i] * b[i];
  printf("inner product %.2f\n", sum);
  return 0;
}
