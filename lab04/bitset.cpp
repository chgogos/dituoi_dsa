#include <bitset>
#include <iostream>

using namespace std;

int main() {
  for (int x = 0; x < 8; x++) {
    bitset<5> b(x);
    cout << x << " ==> " << b << " bits set " << b.count() << endl;
  }
}