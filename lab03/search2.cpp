#include "binary_search.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  int a[] = {11, 45, 53, 60, 67, 72, 88, 91, 94, 98};
  int key;
  cout << "Search for: ";
  cin >> key;
  int pos = binary_search(a, 10, key);
  if (pos == -1)
    cout << "Not found" << endl;
  else
    cout << "Found at position " << pos << endl;
}
