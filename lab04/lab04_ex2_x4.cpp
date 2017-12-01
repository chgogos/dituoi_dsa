#include "linked_list.cpp"
#include "static_list.cpp"
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
  string code;
  int balance;
  bool operator<(customer other) { return code < other.code; }
};

string generate_random_code(int k) {
  string code{};
  string letters_en("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  for (int j = 0; j < k; j++) {
    char c{letters_en[uni2(*mt)]};
    code += c;
  }
  return code;
}

// #### START STATIC LIST
void generate_data_static_list(static_list<customer> &static_list, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.code = generate_random_code(10);
    c.balance = uni1(*mt);
    push_back(static_list, c);
  }
}

void print_customers_static_list(static_list<customer> &static_list, int k) {
  cout << "LIST SIZE=" << static_list.size << ": ";
  for (int i = 0; i < k; i++) {
    customer cu = access(static_list, i);
    cout << cu.code << " - " << cu.balance << " ";
  }
  cout << endl;
}

void total_balance_static_list(static_list<customer> &static_list, char c) {
  int sum = 0;
  for (int i = 0; i < static_list.size; i++) {
    customer cu = access(static_list, i);
    if (cu.code.at(0) == c)
      sum += cu.balance;
  }
  cout << "Total balance for customers having code starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_static_list(static_list<customer> &static_list,
                                     char c) {
  int i = 0;
  while (i < static_list.size) {
    customer cu = access(static_list, i);
    if (cu.code.at(0) == c) {
      customer ncu;
      ncu.code = cu.code;
      reverse(ncu.code.begin(), ncu.code.end());
      ncu.balance = cu.balance;
      insert(static_list, i + 1, ncu);
      i++;
    }
    i++;
  }
}

void remove_customers_static_list(static_list<customer> &static_list, char c) {
  int i = 0;
  while (i < static_list.size) {
    customer cu = access(static_list, i);
    if (cu.code.at(0) == c)
      delete_item(static_list, i);
    else
      i++;
  }
}

void test_static_list() {
  cout << "Testing static list" << endl;
  cout << "########################################################" << endl;
  auto t1 = high_resolution_clock::now();
  struct static_list<customer> static_list;
  generate_data_static_list(static_list, 40000);
  auto t2 = high_resolution_clock::now();
  print_customers_static_list(static_list, 5);
  auto duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "A(random customers generation). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_static_list(static_list, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "B(total balance for customers having code starting with A). Time "
          "elapsed: "
       << duration << " microseconds " << setprecision(3)
       << duration / 1000000.0 << " seconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_static_list(static_list, 'G');
  t2 = high_resolution_clock::now();
  print_customers_static_list(static_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "C(insert new customers). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_static_list(static_list, 'B');
  t2 = high_resolution_clock::now();
  print_customers_static_list(static_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "D(remove customers). Time elapsed: " << duration << " microseconds "
       << setprecision(3) << duration / 1000000.0 << " seconds" << endl;
  cout << "########################################################" << endl;
}
// #### END STATIC LIST

// #### START LINKED LIST
void generate_data_linked_list(linked_list<customer> &linked_list, int N) {
  struct node<customer> *current, *next_customer;
  current = new node<customer>();
  current->data.code = generate_random_code(10);
  current->data.balance = uni1(*mt);
  current->next = NULL;
  linked_list.head = current;
  linked_list.size++;
  for (int i = 1; i < N; i++) {
    next_customer = new node<customer>();
    next_customer->data.code = generate_random_code(10);
    next_customer->data.balance = uni1(*mt);
    next_customer->next = NULL;
    current->next = next_customer;
    current = next_customer;
    linked_list.size++;
  }
}

void print_customers_linked_list(linked_list<customer> &linked_list, int k) {
  cout << "LIST SIZE=" << linked_list.size << ": ";
  for (int i = 0; i < k; i++) {
    customer cu = access(linked_list, i);
    cout << cu.code << " - " << cu.balance << " ";
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
    if (cu.code.at(0) == c)
      sum += cu.balance;
    ptr = ptr->next;
    i++;
  }
  cout << "Total balance for customers having code starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_linked_list(linked_list<customer> &linked_list,
                                     char c) {
  struct node<customer> *ptr = linked_list.head;
  while (ptr != NULL) {
    customer cu = ptr->data;
    if (cu.code.at(0) == c) {
      customer ncu;
      ncu.code = cu.code;
      reverse(ncu.code.begin(), ncu.code.end());
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
    if (cu.code.at(0) == c) {
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
    if (cu.code.at(0) == c) {
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

void test_linked_list() {
  cout << "Testing linked list" << endl;
  cout << "########################################################" << endl;
  struct linked_list<customer> linked_list;
  auto t1 = high_resolution_clock::now();
  generate_data_linked_list(linked_list, 40000);
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
  cout << "B(total balance for customers having code starting with A). Time "
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
  //	remove_customers_linked_list_alt(linked_list, 'B');
  t2 = high_resolution_clock::now();
  print_customers_linked_list(linked_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "D(remove customers). Time elapsed: " << duration << " microseconds "
       << setprecision(3) << duration / 1000000.0 << " seconds" << endl;
  cout << "########################################################" << endl;
}
// #### END LINKED LIST

// #### START VECTOR
void generate_data_stl_vector(vector<customer> &stl_vector, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.code = generate_random_code(10);
    c.balance = uni1(*mt);
    stl_vector.push_back(c);
  }
}

void print_customers_stl_vector(vector<customer> &stl_vector, int k) {
  cout << "LIST SIZE=" << stl_vector.size() << ": ";
  int c = 0;
  for (customer cu : stl_vector) {
    cout << cu.code << " - " << cu.balance << " ";
    if (++c == k)
      break;
  }
  cout << endl;
}

void total_balance_stl_vector(vector<customer> &stl_vector, char c) {
  int sum = 0;
  for (customer cu : stl_vector)
    if (cu.code.at(0) == c)
      sum += cu.balance;
  cout << "Total balance for customers having code starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_stl_vector(vector<customer> &stl_vector, char c) {
  auto i = stl_vector.begin();
  while (i != stl_vector.end()) {
    customer cu = *i;
    if (cu.code.at(0) == c) {
      customer ncu;
      ncu.code = cu.code;
      reverse(ncu.code.begin(), ncu.code.end());
      ncu.balance = cu.balance;
      i++;
      stl_vector.insert(i, ncu);
    }
    i++;
  }
}

void remove_customers_stl_vector(vector<customer> &stl_vector, char c) {
  auto i = stl_vector.begin();
  while (i != stl_vector.end()) {
    customer cu = *i;
    if (cu.code.at(0) == c) {
      i = stl_vector.erase(i);
    } else
      i++;
  }
}

void test_stl_vector() {
  cout << "Testing stl vector" << endl;
  cout << "########################################################" << endl;
  auto t1 = high_resolution_clock::now();
  vector<customer> stl_vector;
  generate_data_stl_vector(stl_vector, 40000);
  auto t2 = high_resolution_clock::now();
  print_customers_stl_vector(stl_vector, 5);
  auto duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "A(random customers generation). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_stl_vector(stl_vector, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "B(total balance for customers having code starting with A). Time "
          "elapsed: "
       << duration << " microseconds " << setprecision(3)
       << duration / 1000000.0 << " seconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_stl_vector(stl_vector, 'G');
  t2 = high_resolution_clock::now();
  print_customers_stl_vector(stl_vector, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "C(insert new customers). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_stl_vector(stl_vector, 'B');
  t2 = high_resolution_clock::now();
  print_customers_stl_vector(stl_vector, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "D(remove customers). Time elapsed: " << duration << " microseconds "
       << setprecision(3) << duration / 1000000.0 << " seconds" << endl;
  cout << "########################################################" << endl;
}
// #### END VECTOR

// #### START LIST
void generate_data_stl_list(list<customer> &stl_list, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.code = generate_random_code(10);
    c.balance = uni1(*mt);
    stl_list.push_back(c);
  }
}

void print_customers_stl_list(list<customer> &stl_list, int k) {
  cout << "LIST SIZE=" << stl_list.size() << ": ";
  int c = 0;
  for (customer cu : stl_list) {
    cout << cu.code << " - " << cu.balance << " ";
    if (++c == k)
      break;
  }
  cout << endl;
}

void total_balance_stl_list(list<customer> &stl_list, char c) {
  int sum = 0;
  for (customer cu : stl_list)
    if (cu.code.at(0) == c)
      sum += cu.balance;
  cout << "Total balance for customers having code starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_stl_list(list<customer> &stl_list, char c) {
  auto i = stl_list.begin();
  while (i != stl_list.end()) {
    customer cu = *i;
    if (cu.code.at(0) == c) {
      customer ncu;
      ncu.code = cu.code;
      reverse(ncu.code.begin(), ncu.code.end());
      ncu.balance = cu.balance;
      i++;
      stl_list.insert(i, ncu);
    } else
      i++;
  }
}

void remove_customers_stl_list(list<customer> &stl_list, char c) {
  auto i = stl_list.begin();
  while (i != stl_list.end()) {
    customer cu = *i;
    if (cu.code.at(0) == c) {
      i = stl_list.erase(i);
    } else
      i++;
  }
}

void test_stl_list() {
  cout << "Testing stl list" << endl;
  cout << "########################################################" << endl;
  auto t1 = high_resolution_clock::now();
  list<customer> stl_list;
  generate_data_stl_list(stl_list, 40000);
  auto t2 = high_resolution_clock::now();
  print_customers_stl_list(stl_list, 5);
  auto duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "A(random customers generation). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_stl_list(stl_list, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "B(total balance for customers having code starting with A). Time "
          "elapsed: "
       << duration << " microseconds " << setprecision(3)
       << duration / 1000000.0 << " seconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_stl_list(stl_list, 'G');
  t2 = high_resolution_clock::now();
  print_customers_stl_list(stl_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "C(insert new customers). Time elapsed: " << duration
       << " microseconds " << setprecision(3) << duration / 1000000.0
       << " seconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_stl_list(stl_list, 'B');
  t2 = high_resolution_clock::now();
  print_customers_stl_list(stl_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "D(remove customers). Time elapsed: " << duration << " microseconds "
       << setprecision(3) << duration / 1000000.0 << " seconds" << endl;
  cout << "########################################################" << endl;
}
// #### END LIST

int main(int argc, char **argv) {
  long seed = 1940;
  mt = new mt19937(seed);
  test_static_list();
  delete mt;
  mt = new mt19937(seed);
  test_linked_list();
  delete mt;
  mt = new mt19937(seed);
  test_stl_vector();
  delete mt;
  mt = new mt19937(seed);
  test_stl_list();
  delete mt;
}