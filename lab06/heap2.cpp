#include "max_heap.cpp"

int main(void) {
  int a[10] = {42, 37, 31, 16, 53, 19, 47, 58, 33, 25};
  for (int i = 0; i < 10; i++) {
    cout << "key " << a[i] << " inserted ==> ";
    insert_key(a[i]);
    print_heap();
  }
  while (heap_size > 0) {
    cout << "key " << heap[1] << " deleted ==> " << heap[1] << " ";
    maximum_key_deletion();
    print_heap();
  }
}
