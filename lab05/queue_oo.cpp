#include <iostream>

using namespace std;

template <typename T> class my_queue {
private:
  T *data;
  int front, rear, capacity, size;

public:
  // constructor
  my_queue(int c) {
    front = 0;
    rear = -1;
    size = 0;
    capacity = c;
    data = new T[capacity];
  }

  // destructor
  ~my_queue() { delete[] data; }

  bool empty() { return (size == 0); }

  void enqueue(T elem) {
    if (size == capacity)
      throw "The queue is full";
    else {
      rear++;
      rear %= capacity;
      data[rear] = elem;
      size++;
    }
  }

  T dequeue() {
    if (size == 0)
      throw "the queue is empty";
    T x = data[front];
    front++;
    front %= capacity;
    size--;
    return x;
  }

  void print(bool internal = true) {
    for (int i = front; i < front + size; i++)
      cout << data[i % capacity] << " ";
    cout << endl;
    if (internal)
      for (int i = 0; i < capacity; i++)
        if (front <= rear && i >= front && i <= rear)
          cout << "[" << i << "]->" << data[i] << " ";
        else if (front >= rear && (i >= front || i <= rear))
          cout << "[" << i << "]->" << data[i] << " ";
        else
          cout << "[" << i << "]->X  ";
    cout << " (front:" << front << " rear:" << rear << ")" << endl;
  }
};

int main() {
  my_queue<int> aqueue(10);
  cout << "1. Enqueue 10 items" << endl;
  for (int i = 51; i <= 60; i++)
    aqueue.enqueue(i);
  aqueue.print();
  cout << "2. Dequeue 5 items" << endl;
  for (int i = 0; i < 5; i++)
    aqueue.dequeue();
  aqueue.print();
  cout << "3. Enqueue 3 items" << endl;
  for (int i = 61; i <= 63; i++)
    aqueue.enqueue(i);
  aqueue.print();
}
