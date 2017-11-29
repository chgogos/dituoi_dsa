/**
 * Code including alternative (but slower) implementations for some methods
 **/
#include "linked_list.cpp"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>
#include <string>

using namespace std;
using namespace std::chrono;

mt19937 *mt;
uniform_int_distribution<int> uni1(0, 5000), uni2(0, 25);

struct customer {
  string name;
  int balance;
  bool operator<(customer other) { return name < other.name; }
};

string generate_random_name(int k) {
  string name{};
  string letters_en("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  for (int j = 0; j < k; j++) {
    char c{letters_en[uni2(*mt)]};
    name += c;
  }
  return name;
}

void generate_data_linked_list(linked_list<customer> &linked_list, int N) {
  struct node<customer> *current, *next_customer;
  current = new node<customer>();
  current->data.name = generate_random_name(10);
  current->data.balance = uni1(*mt);
  current->next = NULL;
  linked_list.head = current;
  linked_list.size++;
  for (int i = 1; i < N; i++) {
    next_customer = new node<customer>();
    next_customer->data.name = generate_random_name(10);
    next_customer->data.balance = uni1(*mt);
    next_customer->next = NULL;
    current->next = next_customer;
    current = next_customer;
    linked_list.size++;
  }
}

// slower alternative for data generation
void generate_data_linked_list_alt(linked_list<customer> &linked_list, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.name = generate_random_name(10);
    c.balance = uni1(*mt);
    push_back(linked_list, c);
  }
}

void print_customers_linked_list(linked_list<customer> &linked_list, int k) {
  cout << "LIST SIZE=" << linked_list.size << ": ";
  for (int i = 0; i < k; i++) {
    customer cu = access(linked_list, i);
    cout << cu.name << " - " << cu.balance << " ";
  }
  cout << endl;
}

void total_balance_linked_list(linked_list<customer> &linked_list, char c) {
  struct node<customer> *ptr;
  ptr = linked_list.head;
  int i = 0;
  int sum = 0;
  while (ptr != NULL) {
    customer cu = ptr->data;
    if (cu.name.at(0) == c)
      sum += cu.balance;
    ptr = ptr->next;
    i++;
  }
  cout << "Total balance for customers having name starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_linked_list(linked_list<customer> &linked_list,
                                     char c) {
  struct node<customer> *ptr = linked_list.head;
  while (ptr != NULL) {
    customer cu = ptr->data;
    if (cu.name.at(0) == c) {
      customer ncu;
      ncu.name = cu.name;
      reverse(ncu.name.begin(), ncu.name.end());
      ncu.balance = cu.balance;
      struct node<customer> *new_node = new node<customer>();
      new_node->data = ncu;
      new_node->next = ptr->next;
      ptr->next = new_node;
      linked_list.size++;
      ptr = new_node->next;
    } else
      ptr = ptr->next;
  }
}

void remove_customers_linked_list(linked_list<customer> &linked_list, char c) {
  struct node<customer> *ptr1;
  while (linked_list.size > 0) {
    customer cu = linked_list.head->data;
    if (cu.name.at(0) == c) {
      ptr1 = linked_list.head;
      linked_list.head = ptr1->next;
      delete ptr1;
      linked_list.size--;
    } else
      break;
  }
  if (linked_list.size == 0)
    return;
  ptr1 = linked_list.head;
  struct node<customer> *ptr2 = ptr1->next;
  while (ptr2 != NULL) {
    customer cu = ptr2->data;
    if (cu.name.at(0) == c) {
      ptr1->next = ptr2->next;
      delete (ptr2);
      ptr2 = ptr1->next;
      linked_list.size--;
    } else {
      ptr1 = ptr2;
      ptr2 = ptr2->next;
    }
  }
}

// slower alternative for customer removal
void remove_customers_linked_list_alt(linked_list<customer> &linked_list,
                                      char c) {
  int i = 0;
  while (i < linked_list.size) {
    struct customer cu = access(linked_list, i);
    if (cu.name.at(0) == c)
      delete_item(linked_list, i);
    else
      i++;
  }
}

int main(int argc, char **argv) {
  long seed = 1940;
  mt = new mt19937(seed);
  cout << "Testing linked list" << endl;
  cout << "########################################################" << endl;
  struct linked_list<customer> linked_list;
  auto t1 = high_resolution_clock::now();
  generate_data_linked_list(linked_list, 40000);
  // generate_data_linked_list_alt(linked_list, 40000);
  auto t2 = high_resolution_clock::now();
  print_customers_linked_list(linked_list, 5);
  auto duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "A(random customers generation). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_linked_list(linked_list, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "B(total balance for customers having name starting with A). Time "
          "elapsed: "
       << duration << " microseconds " << setprecision(3)
       << duration / 1000000.0 << " seconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_linked_list(linked_list, 'G');
  t2 = high_resolution_clock::now();
  print_customers_linked_list(linked_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "C(insert new customers). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_linked_list(linked_list, 'B');
  // remove_customers_linked_list_alt(linked_list, 'B');
  t2 = high_resolution_clock::now();
  print_customers_linked_list(linked_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "D(remove customers). Time elapsed: " << duration << " microseconds "
       << setprecision(3) << duration / 1000000.0 << " seconds" << endl;
  cout << "########################################################" << endl;
  delete mt;
}