#include <iostream>

using namespace std;
struct node
{
  int data;
  struct node *next;
};

// C++ style (using references)
void push_front(struct node *&head, int data)
{
  struct node *new_node = new node();
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

int main(void)
{
  struct node *head;
  push_front(head, 5);
  push_front(head, 7);
  push_front(head, 2);

  for (struct node *ptr = head; ptr != NULL; ptr = ptr->next)
  {
    cout << ptr->data << " ";
  }
  cout << endl;
}