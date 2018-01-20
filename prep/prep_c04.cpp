#include <iostream>
#include <random>

using namespace std;

int main() {
  int data[10][10] = {0};

  // fill and print matrix
  mt19937 mt(123);
  uniform_int_distribution<int> uni(0, 1);
  for (int i = 0; i < 10; i++)
    for (int j = i + 1; j < 10; j++) {
      data[i][j] = uni(mt);
      data[j][i] = data[i][j];
    }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      cout << data[i][j] << " ";
    cout << endl;
  }

  int max = 0;
  int degree[10] = {0};
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      if (data[i][j] > 0)
        degree[i]++;
    cout << "Vertex:" << i << " degree=" << degree[i] << endl;
    if (degree[i] > max)
      max = degree[i];
  }
  cout << "Max degree=" << max << ", vertices having max degree: ";
  for (int i = 0; i < 10; i++)
    if (degree[i] == max)
      cout << i << " ";
  cout << endl;
}
