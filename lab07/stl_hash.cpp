#include <iostream>
#include <string>
using namespace std;

int main() {
  double d1 = 1000.1;
  double d2 = 1000.2;
  hash<double> d_hash;
  cout << "The hash value for: (" << d1 << ") is " << d_hash(d1) << endl;
  cout << "The hash value for: (" << d2 << ") is " << d_hash(d2) << endl;

  char c1[15] = "This is a test";
  char c2[16] = "This is a test.";
  hash<char *> c_strhash;
  cout << "The hash value for: (" << c1 << ") is " << c_strhash(c1) << endl;
  cout << "The hash value for: (" << c2 << ") is " << c_strhash(c2) << endl;

  string s1 = "This is a test";
  string s2 = "This is a test.";
  hash<string> strhash;
  cout << "The hash value for: (" << s1 << ") is " << strhash(s1) << endl;
  cout << "The hash value for: (" << s2 << ") is " << strhash(s2) << endl;
}
