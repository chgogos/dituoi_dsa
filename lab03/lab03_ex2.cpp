#include "binary_search.cpp"
#include "interpolation_search.cpp"
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void benchmark_search_algorithm(string alg) {
  clock_t t1, t2;
  mt19937 mt(1729);
  uniform_int_distribution<int> dist(0, 1000000);
  int M = 100000;
  int keys[M];
  for (int i = 0; i < M; i++) {
    keys[i] = dist(mt);
  }
  int sizes[] = {5000, 10000, 20000, 40000, 80000, 160000, 320000};
  for (int i = 0; i < 7; i++) {
    int N = sizes[i];
    int *a = new int[N];
    for (int i = 0; i < N; i++)
      a[i] = dist(mt);
    sort(a, a + N);

    auto t1 = high_resolution_clock::now();
    int c = 0;
    if (alg.compare("binary-search") == 0) {
      for (int j = 0; j < M; j++)
        if (binary_search(a, 0, N - 1, keys[j]) != -1)
          c++;
    } else if (alg.compare("interpolation-search") == 0) {
      for (int j = 0; j < M; j++)
        if (interpolation_search(a, 0, N - 1, keys[j]) != -1)
          c++;
    } else if (alg.compare("STL-binary-search") == 0)
      for (int j = 0; j < M; j++)
        if (binary_search(a, a + N, keys[j]))
          c++;
    auto t2 = high_resolution_clock::now();
    
    auto elapsed_time = duration_cast<milliseconds>(t2 - t1).count();
    cout << fixed << setprecision(3);
    cout << "Elapsed time " << alg << "\t" << sizes[i] << "\t" << elapsed_time
         << " milliseconds" << endl;
    delete[] a;
  }
}

int main(int argc, char **argv) {
  benchmark_search_algorithm("binary-search");
  cout << "#####################################" << endl;
  benchmark_search_algorithm("interpolation-search");
  cout << "#####################################" << endl;
  benchmark_search_algorithm("STL-binary-search");
  cout << "#####################################" << endl;
}
