#include "hashes.cpp"
#include <iostream>

using namespace std;

int main() {
  constexpr int HT_SIZE = 101;
  string keys[] = {"nikos", "maria", "petros", "kostas"};
  for (string key : keys) {
    size_t h0 = hash0(key) % HT_SIZE;
    size_t h1 = hash1(key) % HT_SIZE;
    size_t h2 = hash2(key) % HT_SIZE;
    size_t h3 = hash3(key) % HT_SIZE;
    cout << "string " << key << " hash0=" << h0 << " hash1=" << h1
         << ", hash2=" << h2 << ", hash3=" << h3 << endl;
  }
}