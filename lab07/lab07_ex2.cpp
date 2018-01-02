#include "random_strings.cpp"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std::chrono;

struct employee {
  string name;
  string address;
};

int main() {
  vector<int> SIZES{2000, 3000, 8000};
  for (int x : SIZES) {
    unordered_map<string, employee> umap;
    // generate x random employees, insert them at the hashtable
    vector<string> names;
    for (int i = 0; i < x; i++) {
      employee ypa;
      ypa.name = generate_random_string(3);
      ypa.address = generate_random_string(20);
      umap[ypa.name] = ypa;
      names.push_back(ypa.name);
    }
    // generate x more names
    for (int i = 0; i < x; i++)
      names.push_back(generate_random_string(3));

    // time execution of 2*x searches in the HashTable
    auto t1 = high_resolution_clock::now();
    int c = 0;
    for (string name : names)
      if (umap.find(name) != umap.end()) {
        // cout << "Employee " << name << " " << umap[name].address << endl;
        c++;
      }
    auto t2 = high_resolution_clock::now();
  std:
    chrono::duration<double, std::micro> duration = t2 - t1;
    cout << "Load factor: " << setprecision(2) << umap.load_factor()
         << " employees found: " << c << " employees not found: " << 2 * x - c
         << " time elapsed: " << std::fixed << duration.count()
         << " microseconds" << endl;
  }
}
