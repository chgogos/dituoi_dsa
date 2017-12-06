#include <iostream>
using namespace std;

// MAXHEAP
const int static HEAP_SIZE_LIMIT = 100000;
int heap[HEAP_SIZE_LIMIT + 1];
int heap_size = 0;

void clear_heap() {
  for (int i = 0; i < HEAP_SIZE_LIMIT + 1; i++)
    heap[i] = 0;
  heap_size = 0;
}

void print_heap(bool newline = true) {
  cout << "HEAP(" << heap_size << ") [";
  for (int i = 1; i <= heap_size; i++)
    if (i == heap_size)
      cout << heap[i];
    else
      cout << heap[i] << " ";
  cout << "]";
  if (newline)
    cout << endl;
}

void heapify(int k) {
  int v = heap[k];
  bool flag = false;
  while (!flag && 2 * k <= heap_size) {
    int j = 2 * k;
    if (j < heap_size)
      if (heap[j] < heap[j + 1])
        j++;
    if (v >= heap[j])
      flag = true;
    else {
      heap[k] = heap[j];
      k = j;
    }
  }
  heap[k] = v;
}

void heap_bottom_up(int *a, int N, bool verbose = false) {
  heap_size = N;
  for (int i = 0; i < N; i++)
    heap[i + 1] = a[i];
  for (int i = heap_size / 2; i >= 1; i--) {
    if (verbose)
      cout << "heapify " << heap[i] << " ";
    heapify(i);
    if (verbose)
      print_heap();
  }
}

int top() { return heap[1]; }

void push(int key) {
  heap_size++;
  heap[heap_size] = key;
  int pos = heap_size;
  while (pos != 1 && heap[pos / 2] < heap[pos]) {
    swap(heap[pos / 2], heap[pos]);
    pos = pos / 2;
  }
}

void pop() {
  swap(heap[1], heap[heap_size]);
  heap_size--;
  heapify(1);
}