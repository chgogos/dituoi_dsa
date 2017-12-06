#include "max_heap.cpp"

int main(void) {
  int a[10] = {42, 37, 31, 16, 53, 19, 47, 58, 33, 25};
  for (int i = 0; i < 10; i++) {
    print_heap(false);
    cout << " ==> push key " << a[i] << " ==> ";
    push(a[i]);
    print_heap();
  }
  while (heap_size > 0) {
    print_heap(false);
    cout << " ==> pop ==> key=" << heap[1] << ", ";
    pop();
    print_heap();
  }
}
