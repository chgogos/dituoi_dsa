#include <iostream>
#include <random>
using namespace std;
int main(int argc, char **argv) {
  mt19937 mt(1821);
  uniform_int_distribution<int> dist(1, 100);
  int n;
  cout << "Enter the size of the vector: ";
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++)
    a[i] = dist(mt);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  delete[] a;
  return 0;
}
