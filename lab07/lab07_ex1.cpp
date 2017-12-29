#include "employees.cpp"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std::chrono;

const int N = 10000; // HashTable size

int simple_string_hash(string &s) {
  int h = 0;
  for (char c : s)
    h += c;
  return h % N;
}

void insert(employee hash_table[], employee &ypa) {
  int pos = simple_string_hash(ypa.name);
  while (hash_table[pos].name != "") {
    pos++;
    pos %= N;
  }
  hash_table[pos] = ypa;
}

bool search(employee hash_table[], string &name, employee &ypa) {
  int pos = simple_string_hash(name);
  int c = 0;
  while (hash_table[pos].name != name) {
    if (hash_table[pos].name == "")
      return false;
    pos++;
    pos %= N;
    c++;
    if (c > N)
      return false;
  }
  ypa = hash_table[pos];
  return true;
}

int main() {
  vector<int> SIZES{2000, 3000, 8000};
  for (int x : SIZES) {
    struct employee hash_table[N];
    // generate x random employees, insert them at the hashtable
    vector<string> names;
    for (int i = 0; i < x; i++) {
      employee ypa;
      ypa.name = generate_random_string(3);
      ypa.address = generate_random_string(20);
      insert(hash_table, ypa);
      names.push_back(ypa.name);
    }
    // generate x more names
    for (int i = 0; i < x; i++)
      names.push_back(generate_random_string(3));
    // time execution of 2*x searches in the HashTable
    auto t1 = high_resolution_clock::now();
    employee ypa;
    int c = 0;
    for (string name : names)
      if (search(hash_table, name, ypa)) {
        // cout << "Employee " << ypa.name << " " << ypa.address << endl;
        c++;
      }
    auto t2 = high_resolution_clock::now();
  std:
    chrono::duration<double, std::micro> duration = t2 - t1;
    cout << "Load factor: " << setprecision(2) << (double)x / (double)N
         << " employees found: " << c << " employees not found: " << 2 * x - c
         << " time elapsed: " << std::fixed << duration.count()
         << " microseconds" << endl;
  }
}
