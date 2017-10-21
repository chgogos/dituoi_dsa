#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  mt19937 mt(1821);
  uniform_int_distribution<int> dist(1, 10000);
  constexpr int N = 1000;
  constexpr int M = 100000;
  int a[N];
  int b[M];
  for (int i = 0; i < N; i++)
    a[i] = dist(mt);
  for (int i = 0; i < M; i++)
    b[i] = dist(mt);
  sort(a, a + N);
  int c = 0;
  for (int i = 0; i < M; i++)
    if (binary_search(a, a + N, b[i]))
      c++;
  cout << "Result " << c << endl;
  return 0;
}
