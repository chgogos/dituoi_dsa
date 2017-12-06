#include "linked_list.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  linked_list<int> alist;
  int choice, position, value;
  do {
    cout << "1.Show list"
         << "-";
    cout << "2.Insert item (back)"
         << "-";
    cout << "3.Insert item (at position)"
         << "-";
    cout << "4.Delete item (from position)"
         << "-";
    cout << "5.Delete all items having value"
         << "-";
    cout << "6.Exit" << endl;
    cout << "Enter choice:";
    cin >> choice;
    if (choice < 1 || choice > 6) {
      cerr << "Choice should be 1 to 6" << endl;
      continue;
    }
    try {
      switch (choice) {
      case 1:
        print_list(alist);
        break;
      case 2:
        cout << "Enter value:";
        cin >> value;
        push_back(alist, value);
        break;
      case 3:
        cout << "Enter position and value:";
        cin >> position >> value;
        insert(alist, position, value);
        break;
      case 4:
        cout << "Enter position:";
        cin >> position;
        delete_item(alist, position);
        break;
      case 5:
        cout << "Enter value:";
        cin >> value;
        int i = 0;
        while (i < alist.size)
          if (access(alist, i) == value)
            delete_item(alist, i);
          else
            i++;
      }
    } catch (out_of_range oor) {
      cerr << "Out of range, try again" << endl;
    }
  } while (choice != 6);
}