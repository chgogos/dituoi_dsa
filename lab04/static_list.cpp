#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX = 50000;
template <class T> struct static_list {
  T elements[MAX];
  int size = 0;
};

// get item at position i
template <class T> T access(static_list<T> &static_list, int i) {
  if (i < 0 || i >= static_list.size)
    throw out_of_range("the index is out of range");
  else
    return static_list.elements[i];
}

// get the position of item x
template <class T> int search(static_list<T> &static_list, T x) {
  for (int i = 0; i < static_list.size; i++)
    if (static_list.elements[i] == x)
      return i;
  return -1;
}

// append item x at the end of the list
template <class T> void push_back(static_list<T> &static_list, T x) {
  if (static_list.size == MAX)
    throw "full list exception";
  static_list.elements[static_list.size] = x;
  static_list.size++;
}

// append item x at position i, shift the rest to the right
template <class T> void insert(static_list<T> &static_list, int i, T x) {
  if (static_list.size == MAX)
    throw "full list exception";
  if (i < 0 || i >= static_list.size)
    throw out_of_range("the index is out of range");
  for (int k = static_list.size; k > i; k--)
    static_list.elements[k] = static_list.elements[k - 1];
  static_list.elements[i] = x;
  static_list.size++;
}

// delete item at position i, shift the rest to the left
template <class T> void delete_item(static_list<T> &static_list, int i) {
  if (i < 0 || i >= static_list.size)
    throw out_of_range("the index is out of range");
  for (int k = i; k < static_list.size; k++)
    static_list.elements[k] = static_list.elements[k + 1];
  static_list.size--;
}

template <class T> void print_list(static_list<T> &static_list) {
  cout << "List: ";
  for (int i = 0; i < static_list.size; i++)
    cout << static_list.elements[i] << " ";
  cout << endl;
}