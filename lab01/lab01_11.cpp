#include <iostream>
using namespace std;
int main(int argc, char **argv) {
  int *a[5];
  for (int i = 0; i < 5; i++) {
    a[i] = new int[i + 1];
    for (int j = 0; j < i + 1; j++)
      a[i][j] = i + j;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i + 1; j++)
      cout << a[i][j] << " ";
    cout << endl;
  }
  for (int i = 0; i < 5; i++)
    delete[] a[i];
  return 0;
}
