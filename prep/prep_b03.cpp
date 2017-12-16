#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *previous;
  struct node *next;
};

struct node *head;
struct node *tail;

void print(struct node *anode) {
  struct node *current = anode;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void print_reverse(struct node *anode) {
  struct node *current = anode;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->previous;
  }
  cout << endl;
}

int main() {
  struct node *node1 = new node{10, NULL};
  struct node *node2 = new node{20, NULL};
  struct node *node3 = new node{30, NULL};

  head = node1;
  tail = node3;
  node1->next = node2;
  node1->previous = NULL;
  node2->next = node3;
  node2->previous = node1;
  node3->next = NULL;
  node3->previous = node2;

  print(head);
  print_reverse(tail);
}