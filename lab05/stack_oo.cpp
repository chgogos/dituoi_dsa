#include <iostream>

using namespace std;

template <typename T> class stack {
private:
  T *data;
  int top, length;

public:
  stack(int size) {
    top = -1;
    length = size;
    data = new T[length];
  }

  ~stack() { delete[] data; }

  void push(T elem) {
    if (top == (length - 1)) {
      cout << "The stack is full." << endl;
      return;
    } else {
      top++;
      data[top] = elem;
    }
  };

  T pop() {
    if (top == -1)
      throw "the stack is empty";
    T v = data[top];
    top--;
    return v;
  };

  void display() {
    for (int i = 0; i <= top; i++)
      cout << data[i] << " ";
    cout << endl;
  };
};

int main() {
  stack<string> astack(10);
  astack.push("a");
  astack.display();
  astack.push("b");
  astack.push("c");
  astack.display();
  astack.pop();
  astack.display();
  astack.pop();
  astack.display();
}