#include <iostream>

using namespace std;
struct node {
  int data;
  struct node *next;
};

int length(struct node *node) {
  int c = 0;
  struct node *current = node;
  while (current != NULL) {
    c++;
    current = current->next;
  }
  return c;
}

int main(void) {
  struct node *node1 = new node{10, NULL};
  struct node *node2 = new node{20, NULL};
  struct node *node3 = new node{30, NULL};
  struct node *node4 = new node{40, NULL};
  struct node *head = node1;
  node1->next=node2;
  node2->next=node3;
  node3->next=node4;
  cout << length(head) << endl;
}
