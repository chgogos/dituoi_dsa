#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;

int main() {
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  mt19937 mt(1821);
  uniform_int_distribution<int> dist(0, 10000);
  double sum = 0.0;
  for (int i = 1; i <= 10000000; i++) {
    int x = dist(mt);
    sum += sqrt(x);
  }
  cout << "The sum is: " << sum << endl;
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds "
       << duration / 1000000.0 << " seconds" << endl;
}
