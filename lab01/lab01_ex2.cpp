#include <iostream>
#include <random>

using namespace std;

int main(int argc, char **argv) {
  int seed = 1729;
  int a[100][100];
  mt19937 mt(seed);
  uniform_int_distribution<int> dist(0, 10000);
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++)
      a[i][j] = dist(mt);
  int b[100];
  int max = 0;
  for (int i = 0; i < 100; i++) {
    int sum = 0;
    for (int j = 0; j < 100; j++)
      sum += a[i][j];
    b[i] = sum;
    if (sum > max)
      max = sum;
  }
  cout << "Maximum row sum: " << max << endl;
  for (int i = 0; i < 100; i++)
    if (b[i] == max)
      cout << "Occurs at row: " << i << endl;
  return 0;
}
