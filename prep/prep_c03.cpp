#include <iostream>

using namespace std;

int main() {
  string a[] = {"arta", "preveza", "ioannina", "igoumenitsa", "metsovo"};
  hash<string> strhash;
  for (int i = 0; i < 5; i++) {
    size_t h = strhash(a[i]);
    cout << "Key: " << a[i] << " #" << h << " #" << h % 7 << endl;
  }

  int collisions = 0;
  for (int i = 0; i < 5; i++) {
    size_t h1 = strhash(a[i]) % 7;
    for (int j = 0; j < 5; j++) {
      if (i == j)
        continue;
      size_t h2 = strhash(a[j]) % 7;
      if (h1 == h2) {
        collisions++;
        break;
      }
    }
  }
  cout << "Keys with collisions=" << collisions << endl;
}
