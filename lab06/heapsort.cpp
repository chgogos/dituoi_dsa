#include "max_heap.cpp"
#include <algorithm>
#include <chrono>
#include <random>

using namespace std::chrono;

void heapsort() {
  while (!empty())
    pop();
}

int main(void) {
  high_resolution_clock::time_point t1, t2;
  mt19937 mt(1940);
  uniform_int_distribution<int> uni(0, 200000);
  int problem_sizes[] = {10000, 20000, 40000, 80000, 100000};
  for (int i = 0; i < 5; i++) {
    clear_heap();
    int N = problem_sizes[i];
    int *a = new int[N];
    for (int i = 0; i < N; i++)
      a[i] = uni(mt);
    heap_bottom_up(a, N);
    t1 = high_resolution_clock::now();
    heapsort();
    t2 = high_resolution_clock::now();
    duration<double, std::milli> duration1 = t2 - t1;
    for (int i = 0; i < N; i++)
      a[i] = uni(mt);
    t1 = high_resolution_clock::now();
    sort(a, a + N);
    t2 = high_resolution_clock::now();
    duration<double, std::milli> duration2 = t2 - t1;
    cout << "SIZE " << N << " heap sort " << duration1.count()
         << "ms std::sort " << duration2.count() << "ms" << endl;
    delete[] a;
  }
}
