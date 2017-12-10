#include <iostream>

using namespace std;

template <typename T> class my_stack {
private:
  T *data;
  int top, capacity;

public:
  // constructor
  my_stack(int c) {
    top = -1;
    capacity = c;
    data = new T[capacity];
  }

  // destructor
  ~my_stack() { delete[] data; }

  bool empty() { return (top == -1); }

  void push(T elem) {
    if (top == (capacity - 1))
      throw "The stack is full";
    else {
      top++;
      data[top] = elem;
    }
  }

  T pop() {
    if (top == -1)
      throw "the stack is empty";
    top--;
    return data[top + 1];
  }

  void print() {
    for (int i = 0; i <= top; i++)
      cout << data[i] << " ";
    cout << endl;
  }
};

int main() {
  my_stack<char> astack(100);
  for (char c = 65; c < 65 + 26; c++)
    astack.push(c);
  astack.print();
  while (!astack.empty()) {
    cout << astack.pop() << " ";
  }
  cout << endl;
}
