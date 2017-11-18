#include "linked_list.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  linked_list<int> alist;
  cout << "#1. Add items 10, 20 and 30" << endl;
  push_back(alist, 10);
  push_back(alist, 20);
  push_back(alist, 30);
  print_list(alist);
  cout << "#2. Insert at position 1 item 15" << endl;
  insert(alist, 1, 15);
  print_list(alist);
  cout << "#3. Delete item at position 0" << endl;
  delete_item(alist, 0);
  print_list(alist);
  cout << "#4. Item at position 2: " << access(alist, 2) << endl;
  try {
    cout << "#5. Item at position -1" << access(alist, -1) << endl;
  } catch (out_of_range oor) {
    cerr << "Exception: " << oor.what() << endl;
  }
  cout << "#6. Search for item 20: " << search(alist, 20) << endl;
  cout << "#7. Search for item 21: " << search(alist, 21) << endl;
  cout << "#8. Delete allocated memory " << endl;
  for (int i = 0; i < alist.size; i++)
    delete_item(alist, i);
}