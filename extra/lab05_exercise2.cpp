/**
 *  http://www.geeksforgeeks.org/implement-stack-using-queue/
 */

#include <iostream>
#include <queue>

using namespace std;

class my_stack {
  queue<int> q1, q2;
  int size;

public:
  my_stack() { size = 0; }
  void push(int x) {
    size++;
    q2.push(x);
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    

  }
};

int main() {}