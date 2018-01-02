#include "hashes.cpp"
#include "random_strings.cpp"
#include <iostream>
#include <set>

using namespace std;
constexpr int HT_SIZE = 10001;

int main() {
  set<int> aset;
  int collisions = 0;
  for (int i = 0; i < 2000; i++) {
    string key = generate_random_string(10);
    size_t h = hash0(key) % HT_SIZE; // 1863 collisions
    // size_t h = hash1(key) % HT_SIZE;  // 172 collisions
    // size_t h = hash2(key) % HT_SIZE; // 188 collisions
    // size_t h = hash3(key) % HT_SIZE; // 196 collisions
    if (aset.find(h) != aset.end())
      collisions++;
    else
      aset.insert(h);
  }
  cout << "number of collisions " << collisions << endl;
}