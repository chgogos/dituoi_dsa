#include <iostream>

using namespace std;
struct node
{
  int data;
  struct node *next = nullptr;
};

int length(node *head)
{
  node *current = head;
  int c = 0;
  while (current != nullptr)
  {
    c++;
    current = current->next;
  }
  return c;
}

int main(void)
{
  node n1, n2, n3;
  n1.data = 12;
  n1.next = &n2;
  n2.data = 99;
  n2.next = &n3;
  n3.data = 37;
  node *head = &n1;
  cout << "The length of the list is: " << length(head) << endl;
}