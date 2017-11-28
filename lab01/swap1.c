#include <stdio.h>

void swap_not_ok(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main(int argc, char **argv) {
  int a = 5, b = 7;
  printf("BEFORE a=%d b=%d\n", a, b);
  swap_not_ok(a, b);
  printf("AFTER  a=%d b=%d\n", a, b);
  printf("BEFORE a=%d b=%d\n", a, b);
  swap(&a, &b);
  printf("AFTER  a=%d b=%d\n", a, b);
  return 0;
}
