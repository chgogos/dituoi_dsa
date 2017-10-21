#include <cstdio>

void swap_cpp(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

int main(int argc, char **argv) {
  int a = 5, b = 7;
  printf("BEFORE a=%d b=%d\n", a, b);
  swap_cpp(a, b);
  printf("AFTER a=%d b=%d\n", a, b);
  return 0;
}
