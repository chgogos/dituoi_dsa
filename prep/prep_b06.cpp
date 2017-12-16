#include <iostream>
#include <vector>

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

  void push_values(vector<T> &elems) {
    if (top + elems.size() >= capacity - 1)
      throw "Not enough space";
    else {
      for (T x : elems) {
        top++;
        data[top] = x;
      }
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
  my_stack<int> astack(100);
  vector<int> v{3, 5, 2, 8, 9, 1};
  astack.push_values(v);
  astack.print();
}
