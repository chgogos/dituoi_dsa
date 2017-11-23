#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> struct node {
  T data;
  struct node<T> *next = NULL;
};

template <class T> struct linked_list {
  struct node<T> *head = NULL;
  int size = 0;
};

// get node item at position i
template <class T>
struct node<T> *access_node(linked_list<T> &linked_list, int i) {
  if (i < 0 || i >= linked_list.size)
    throw out_of_range("the index is out of range");
  struct node<T> *current = linked_list.head;
  for (int k = 0; k < i; k++)
    current = current->next;
  return current;
}

// get node item at position i
template <class T>
T access(linked_list<T> &linked_list, int i) {
  struct node<T> *item = access_node(linked_list, i);
  return item->data;
}

// get the position of item x
template <class T> int search(linked_list<T> &linked_list, T x) {
  struct node<T> *current = linked_list.head;
  int i = 0;
  while (current != NULL) {
    if (current->data == x)
      return i;
    i++;
    current = current->next;
  }
  return -1;
}

// append item x at the end of the list
template <class T> void push_back(linked_list<T> &l, T x) {
  struct node<T> *new_node, *current;
  new_node = new node<T>();
  new_node->data = x;
  new_node->next = NULL;
  current = l.head;
  if (current == NULL) {
    l.head = new_node;
    l.size++;
  } else {
    while (current->next != NULL)
      current = current->next;
    current->next = new_node;
    l.size++;
  }
}

// append item x after position i
template <class T> void insert_after(linked_list<T> &linked_list, int i, T x) {
  if (i < 0 || i >= linked_list.size)
    throw out_of_range("the index is out of range");
  struct node<T> *ptr = access_node(linked_list, i);
  struct node<T> *new_node = new node<T>();
  new_node->data = x;
  new_node->next = ptr->next;
  ptr->next = new_node;
  linked_list.size++;
}

// append item at the head
template <class T> void insert_head(linked_list<T> &linked_list, T x) {
  struct node<T> *new_node = new node<T>();
  new_node->data = x;
  new_node->next = linked_list.head;
  linked_list.head = new_node;
  linked_list.size++;
}

// append item x at position i
template <class T> void insert(linked_list<T> &linked_list, int i, T x) {
  if (i == 0)
    insert_head(linked_list, x);
  else
    insert_after(linked_list, i - 1, x);
}

// delete item at position i
template <class T> void delete_item(linked_list<T> &l, int i) {
  if (i < 0 || i >= l.size)
    throw out_of_range("the index is out of range");
  if (i == 0) {
    struct node<T> *ptr = l.head;
    l.head = ptr->next;
    delete ptr;
  } else {
    struct node<T> *ptr = access_node(l, i - 1);
    struct node<T> *to_be_deleted = ptr->next;
    ptr->next = to_be_deleted->next;
    delete to_be_deleted;
  }
  l.size--;
}

template <class T> void print_list(linked_list<T> &l) {
  cout << "List: ";
  struct node<T> *current = l.head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}