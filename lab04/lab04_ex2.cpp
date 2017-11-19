#include "linked_list.cpp"
#include "static_list.cpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <random>
#include <string>

using namespace std;
using namespace std::chrono;

mt19937 *mt;
uniform_int_distribution<int> uni1(0, 5000);
uniform_int_distribution<int> uni2(0, 25);

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

// #### START STATIC LIST
void generate_data_static_list(static_list<customer> &static_list, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.name = generate_random_name(10);
    c.balance = uni1(*mt);
    push_back(static_list, c);
  }
}

void print_customers_static_list(static_list<customer> &static_list, int k) {
  for (int i = 0; i < k; i++) {
    customer cu = access(static_list, i);
    cout << cu.name << " - " << cu.balance << " ";
  }
  cout << endl << "SIZE " << static_list.size << endl;
}

void total_balance_static_list(static_list<customer> &static_list, char c) {
  int sum = 0;
  for (int i = 0; i < static_list.size; i++) {
    customer cu = access(static_list, i);
    if (cu.name.at(0) == c)
      sum += cu.balance;
  }
  cout << "Total balance for customers having name starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_static_list(static_list<customer> &static_list,
                                     char c) {
  int i = 0;
  while (i < static_list.size) {
    customer cu = access(static_list, i);
    if (cu.name.at(0) == c) {
      customer ncu;
      ncu.name = cu.name;
      reverse(ncu.name.begin(), ncu.name.end());
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
    if (cu.name.at(0) == c)
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
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_static_list(static_list, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_static_list(static_list, 'G');
  t2 = high_resolution_clock::now();
  print_customers_static_list(static_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_static_list(static_list, 'B');
  t2 = high_resolution_clock::now();
  print_customers_static_list(static_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;
  cout << "########################################################" << endl;
}
// #### END STATIC LIST

// #### START LINKED LIST
void generate_data_linked_list(linked_list<customer> &linked_list, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.name = generate_random_name(10);
    c.balance = uni1(*mt);
    push_back(linked_list, c);
  }
}

void print_customers_linked_list(linked_list<customer> &linked_list, int k) {
  for (int i = 0; i < k; i++) {
    customer cu = access(linked_list, i);
    cout << cu.name << " - " << cu.balance << " ";
  }
  cout << endl << "SIZE " << linked_list.size << endl;
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
  int i = 0;
  while (i < linked_list.size) {
    struct customer cu = access(linked_list, i);
    if (cu.name.at(0) == c)
      delete_item(linked_list, i);
    else
      i++;
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
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_linked_list(linked_list, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_linked_list(linked_list, 'G');
  t2 = high_resolution_clock::now();
  print_customers_linked_list(linked_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_linked_list(linked_list, 'B');
  //	remove_customers_linked_list_alt(linked_list, 'B');
  t2 = high_resolution_clock::now();
  print_customers_linked_list(linked_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;
  cout << "########################################################" << endl;
}
// #### END LINKED LIST

// #### START VECTOR
void generate_data_stl_vector(vector<customer> &stl_vector, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.name = generate_random_name(10);
    c.balance = uni1(*mt);
    stl_vector.push_back(c);
  }
}

void print_customers_stl_vector(vector<customer> &stl_vector, int k) {
  int c = 0;
  for (customer cu : stl_vector) {
    cout << cu.name << " - " << cu.balance << " ";
    if (++c == k)
      break;
  }
  cout << endl << "SIZE " << stl_vector.size() << endl;
}

void total_balance_stl_vector(vector<customer> &stl_vector, char c) {
  int sum = 0;
  for (customer cu : stl_vector)
    if (cu.name.at(0) == c)
      sum += cu.balance;
  cout << "Total balance for customers having name starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_stl_vector(vector<customer> &stl_vector, char c) {
  auto i = stl_vector.begin();
  while (i != stl_vector.end()) {
    customer cu = *i;
    if (cu.name.at(0) == c) {
      customer ncu;
      ncu.name = cu.name;
      reverse(ncu.name.begin(), ncu.name.end());
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
    if (cu.name.at(0) == c) {
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
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_stl_vector(stl_vector, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_stl_vector(stl_vector, 'G');
  t2 = high_resolution_clock::now();
  print_customers_stl_vector(stl_vector, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_stl_vector(stl_vector, 'B');
  t2 = high_resolution_clock::now();
  print_customers_stl_vector(stl_vector, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;
  cout << "########################################################" << endl;
}
// #### END VECTOR

// #### START LIST
void generate_data_stl_list(list<customer> &stl_list, int N) {
  for (int i = 0; i < N; i++) {
    customer c;
    c.name = generate_random_name(10);
    c.balance = uni1(*mt);
    stl_list.push_back(c);
  }
}

void print_customers_stl_list(list<customer> &stl_list, int k) {
  int c = 0;
  for (customer cu : stl_list) {
    cout << cu.name << " - " << cu.balance << " ";
    if (++c == k)
      break;
  }
  cout << endl << "SIZE " << stl_list.size() << endl;
}

void total_balance_stl_list(list<customer> &stl_list, char c) {
  int sum = 0;
  for (customer cu : stl_list)
    if (cu.name.at(0) == c)
      sum += cu.balance;
  cout << "Total balance for customers having name starting with character "
       << c << " is " << sum << endl;
}

void add_extra_customers_stl_list(list<customer> &stl_list, char c) {
  auto i = stl_list.begin();
  while (i != stl_list.end()) {
    customer cu = *i;
    if (cu.name.at(0) == c) {
      customer ncu;
      ncu.name = cu.name;
      reverse(ncu.name.begin(), ncu.name.end());
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
    if (cu.name.at(0) == c) {
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
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  total_balance_stl_list(stl_list, 'A');
  t2 = high_resolution_clock::now();
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  add_extra_customers_stl_list(stl_list, 'G');
  t2 = high_resolution_clock::now();
  print_customers_stl_list(stl_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  remove_customers_stl_list(stl_list, 'B');
  t2 = high_resolution_clock::now();
  print_customers_stl_list(stl_list, 5);
  duration = duration_cast<microseconds>(t2 - t1).count();
  cout << "Time elapsed: " << duration << " microseconds" << endl;
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