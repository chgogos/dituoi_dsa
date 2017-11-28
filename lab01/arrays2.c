#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
  int n;
  printf("Enter the size of the vector: ");
  fflush(stdout);
  scanf("%d", &n);
  int *a = (int *)malloc(sizeof(int) * n);
  //	srand(time(NULL));
  srand(1821);

  for (int i = 0; i < n; i++)
    a[i] = (rand() % 100) + 1;

  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);

  free(a);
  return 0;
}
