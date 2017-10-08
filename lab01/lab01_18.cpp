#include <cstdio>
#include <cstdlib>
#include <iostream>


using namespace std;

int main(int argc, char **argv) {
  const char *fn = "data_int_10000.txt";
  int N = 10000;
  srand(1729);

  FILE *fp = fopen(fn, "w");
  if (fp == NULL) {
    printf("error opening file");
    exit(-1);
  }
  for (int i = 0; i < N; i++)
    fprintf(fp, "%d ", rand() % 10000 + 1);
  fclose(fp);

  fp = fopen(fn, "r");
  if (fp == NULL) {
    printf("error opening file");
    exit(-1);
  }
  int *data = new int[N];
  int i = 0;
  while (!feof(fp)) {
    fscanf(fp, "%d", &data[i]);
    i++;
  }
  fclose(fp);
  int max = data[0];
  for (i = 1; i < N; i++)
    if (data[i] > max)
      max = data[i];
  printf("Maximum value %d\n", max);
  int *freq = new int[max + 1];
  for (i = 0; i < max + 1; i++)
    freq[i] = 0;
  for (i = 0; i < N; i++)
    freq[data[i]]++;
  int max2 = 0;
  for (i = 0; i < max + 1; i++)
    if (freq[i] > max2)
      max2 = freq[i];
  for (i = 0; i < max + 1; i++)
    if (freq[i] == max2)
      printf("Value %d exists %d times\n", i, max2);
  delete[] freq;
  return 0;
}
