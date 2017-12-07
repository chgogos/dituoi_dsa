#include <chrono>
#include <iomanip>
#include <iostream>
#include <queue>
#include <random>

using namespace std;
using namespace std::chrono;

double medians(int a[], int N) {
  priority_queue<int, std::vector<int>, std::less<int>> pq1;
  priority_queue<int, std::vector<int>, std::greater<int>> pq2;
  int first = a[0];
  int second = a[1];
  if (first < second) {
    pq1.push(first);
    pq2.push(second);
  } else {
    pq2.push(first);
    pq1.push(second);
  }
  double sum = first + (first + second) / 2.0;
  for (int i = 2; i < N; i++) {
    int x = a[i];
    if (x <= pq1.top())
      pq1.push(x);
    else
      pq2.push(x);
    if (pq1.size() < pq2.size()) {
      pq1.push(pq2.top());
      pq2.pop();
    }
    double median;
    if (pq1.size() == pq2.size())
      median = (pq1.top() + pq2.top()) / 2.0;
    else
      median = pq1.top();
    sum += median;
  }
  return sum;
}

int main(int argc, char **argv) {
  high_resolution_clock::time_point t1, t2;
  t1 = high_resolution_clock::now();
  mt19937 mt(1940);
  uniform_int_distribution<int> uni(0, 200000);
  int N = 500000;
  int *a = new int[N];
  for (int i = 0; i < N; i++)
    a[i] = uni(mt);
  double sum = medians(a, N);
  delete[] a;
  t2 = high_resolution_clock::now();
  duration<double, std::milli> duration = t2 - t1;
  cout.precision(2);
  cout << "Moving medians sum = " << std::fixed << sum << " elapsed time "
       << duration.count() << "ms" << endl;
}
