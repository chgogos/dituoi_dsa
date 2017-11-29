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
  struct node *node4 = new node{22, NULL};
  struct node *node3 = new node{12, node4};
  struct node *node2 = new node{21, node3};
  struct node *node1 = new node{16, node2};
  struct node *head = node1;

  cout << length(head) << endl;
}