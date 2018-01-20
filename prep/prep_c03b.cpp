#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  vector<string> v = {"arta", "preveza", "ioannina", "igoumenitsa", "metsovo"};
  hash<string> strhash;
  set<size_t> aset;
  for (string s : v) {
    size_t h = strhash(s);
    aset.insert(h % 7);
    cout << "Key: " << s << " #" << h << " #" << h % 7 << endl;
  }
  cout << "Keys with collisions=" << v.size() - aset.size() + 1 << endl;
}
