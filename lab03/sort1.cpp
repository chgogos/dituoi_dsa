#include "insertion_sort.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int a[] = {45, 32, 16, 11, 7, 18, 21, 16, 11, 15};
  cout << "Sort using insertion sort" << endl;
  insertion_sort(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
}
