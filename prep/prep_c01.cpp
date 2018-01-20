#include <iostream>
#include <string>

using namespace std;

size_t my_hash(string &key) {
  while (key.size() < 3)
    key += " ";
  size_t sum = key[0] * 49 + key[1] * 7 + key[2];
  return sum;
}

int main() {
  string text1 = "DOG";
  string text2 = "D";
  cout << "Key:" << text1 << " hash:" << my_hash(text1) << endl;
  cout << "Key:" << text2 << " hash:" << my_hash(text2) << endl;
}