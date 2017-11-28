#include <stdio.h>

int main(int argc, char **argv) {
  int a, b;
  int *p;
  p = &a;
  *p = 5;
  b = *p + 1;
  printf("variable a=%d address=%p\n", a, &a);
  printf("variable b=%d address=%p\n", b, &b);
  printf("pointer  p=%p *p=%d\n", p, *p);
  return 0;
}