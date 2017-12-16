#include <iostream>

using namespace std;
struct node {
  int data;
  struct node *next;
};

int sum(struct node *node) {
  int s = 0;
  struct node *current = node;
  while (current != NULL) {
    s += current->data;
    current = current->next;
  }
  return s;
}

int main(void) {
  struct node *node1 = new node{10, NULL};
  struct node *node2 = new node{20, NULL};
  struct node *node3 = new node{30, NULL};
  struct node *node4 = new node{40, NULL};
  struct node *head = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  cout << sum(head) << endl;
}
