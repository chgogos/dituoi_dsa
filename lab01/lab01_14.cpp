#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {
  FILE *fp = fopen("data_int_100.txt", "w");
  srand(time(NULL));
  for (int i = 0; i < 100; i++)
    fprintf(fp, "%d ", rand() % 1000 + 1);
  fclose(fp);

  fp = fopen("data_int_100.txt", "r");
  if (fp == NULL) {
    printf("error opening file");
    exit(-1);
  }
  int x;
  while (!feof(fp)) {
    fscanf(fp, "%d", &x);
    printf("%d ", x);
  }
  fclose(fp);
  return 0;
}
