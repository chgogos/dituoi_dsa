#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
  int a[10] = {15, 16, 13, 23, 45, 67, 11, 22, 37, 10};
  cout << "priority queue (MAXHEAP): ";
  priority_queue<int> pq1(a, a + 10);
  while (!pq1.empty()) {
    int x = pq1.top();
    pq1.pop();
    cout << x << " ";
  }
  cout << endl;

  cout << "priority queue (MINHEAP): ";
  priority_queue<int, std::vector<int>, std::greater<int>> pq2(a, a + 10);
  while (!pq2.empty()) {
    int x = pq2.top();
    pq2.pop();
    cout << x << " ";
  }
  cout << endl;
}
