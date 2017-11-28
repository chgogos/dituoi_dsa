#include "max_heap.cpp"

int main(void) {
  cout << "#### Test heap construction with heapify ####" << endl;
  int a[10] = {42, 37, 31, 16, 53, 19, 47, 58, 33, 25};
  heap_bottom_up(a, 10, true);
  print_heap();
}
