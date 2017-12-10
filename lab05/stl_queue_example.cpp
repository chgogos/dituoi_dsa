#include <iostream>
#include <queue>

using namespace std;

int main() {
  cout << "std::queue" << endl;
  queue<int> aqueue;
  cout << "1. Enqueue 10 items" << endl;
  for (int i = 51; i < 60; i++) {
    cout << i << " ";
    aqueue.push(i);
  }
  cout << endl << "2. Dequeue 5 items" << endl;
  for (int i = 0; i < 5; i++) {
    cout << aqueue.front() << " ";
    aqueue.pop();
  }
  cout << endl << "3. Enqueue 3 items" << endl;
  for (int i = 61; i <= 63; i++) {
    cout << i << " ";
    aqueue.push(i);
  }
  while (!aqueue.empty()) {
    cout << aqueue.front() << " ";
    aqueue.pop();
  }
  cout << endl;
}