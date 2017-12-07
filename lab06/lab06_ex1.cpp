#include "max_heap.cpp"
#include <chrono>
#include <queue>
#include <random>


using namespace std::chrono;

int main(void) {
  constexpr int N = 100000;
  mt19937 mt(1821);
  int a[N];
  uniform_int_distribution<int> dist(-1000000, 1000000);
  for (int i = 0; i < N; i++)
    a[i] = dist(mt);

  auto t1 = high_resolution_clock::now();
  heap_bottom_up(a, N, false);
  auto t2 = high_resolution_clock::now();
  std::chrono::duration<double, std::micro> duration_micro_sec = t2 - t1;
  cout << "A. Top item: " << top() << endl;
  cout << "Time elapsed (heap_bottom_up): " << duration_micro_sec.count()
       << " microseconds " << endl;

  clear_heap();

  t1 = high_resolution_clock::now();
  for (int i = 0; i < N; i++)
    push(a[i]);
  t2 = high_resolution_clock::now();
  duration_micro_sec = t2 - t1;
  cout << "B. Top item: " << top() << endl;
  cout << "Time elapsed (push): " << duration_micro_sec.count()
       << " microseconds " << endl;

  t1 = high_resolution_clock::now();
  priority_queue<int> pq(a, a + N);
  t2 = high_resolution_clock::now();
  duration_micro_sec = t2 - t1;
  cout << "C. Top item: " << pq.top() << endl;
  cout << "Time elapsed (push): " << duration_micro_sec.count()
       << " microseconds " << endl;
}