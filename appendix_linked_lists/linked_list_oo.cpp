/**
 * adapted from
 * https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
 */

#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

class list
{
private:
  node *head, *tail;

public:
  list()
  {
    head = NULL;
    tail = NULL;
  }
  void createnode(int value)
  {
    node *new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL)
    {
      head = new_node;
      tail = new_node;
    }
    else
    {
      tail->next = new_node;
      tail = new_node;
    }
  }

  void display()
  {
    node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << "\t";
      temp = temp->next;
    }
    cout << endl;
  }

  void insert_start(int value)
  {
    node *new_node = new node;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
  }

  void insert_position(int pos, int value)
  {
    node *pre;
    node *cur = head;
    node *new_node = new node;
    for (int i = 0; i < pos; i++)
    {
      pre = cur;
      cur = cur->next;
    }
    new_node->data = value;
    pre->next = new_node;
    new_node->next = cur;
  }

  void delete_first()
  {
    node *temp = head;
    head = head->next;
    delete temp;
  }

  void delete_last()
  {
    node *current = head;
    node *previous;
    while (current->next != NULL)
    {
      previous = current;
      current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
  }

  void delete_position(int pos)
  {
    if (pos == 0)
      delete_first();
    else
    {
      node *current = head;
      node *previous;
      for (int i = 0; i < pos; i++)
      {
        previous = current;
        current = current->next;
      }
      previous->next = current->next;
    }
  }
};

int main()
{
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
  cout << "delete item at position 1" << endl;
  alist.delete_position(1);
  alist.display();
}