/**
 * https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
 */

#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

class list {
private:
  node *head, *tail;

public:
  list() {
    head = NULL;
    tail = NULL;
  }
  void createnode(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL) {
      head = temp;
      tail = temp;
      temp = NULL;
    } else {
      tail->next = temp;
      tail = temp;
    }
  }

  void display() {
    node *temp = head;
    while (temp != NULL) {
      cout << temp->data << "\t";
      temp = temp->next;
    }
    cout << endl;
  }

  void insert_start(int value) {
    node *temp = new node;
    temp->data = value;
    temp->next = head;
    head = temp;
  }

  void insert_position(int pos, int value) {
    node *pre;
    node *cur = head;
    node *temp = new node;
    for (int i = 0; i < pos; i++) {
      pre = cur;
      cur = cur->next;
    }
    temp->data = value;
    pre->next = temp;
    temp->next = cur;
  }

  void delete_first() {
    node *temp = head;
    head = head->next;
    delete temp;
  }

  void delete_last() {
    node *current = head;
    node *previous;
    while (current->next != NULL) {
      previous = current;
      current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
  }

  void delete_position(int pos) {
    node *current = new node;
    node *previous = new node;
    current = head;
    for (int i = 1; i < pos; i++) {
      previous = current;
      current = current->next;
    }
    previous->next = current->next;
  }
};

int main() {
  list alist;
  cout << "insert 3 items (10,20,30)" << endl;
  alist.createnode(10);
  alist.createnode(20);
  alist.createnode(30);
  alist.display();
  cout << "insert at start item 5" << endl;
  alist.insert_start(5);
  alist.display();
  cout << "insert at position 1 item 2" << endl;
  alist.insert_position(1, 2);
  alist.display();
  cout << "delete last item" << endl;
  alist.delete_last();
  alist.display();
  cout << "delete first item" << endl;
  alist.delete_first();
  alist.display();
}