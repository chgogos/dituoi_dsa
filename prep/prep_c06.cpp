#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<char, int> amap;
  string s;
  cout << "Enter text: ";
  getline(cin, s); // reads a sentence
  while (s != "") {
    for (char c : s)
      if (amap.find(c) == amap.end())
        amap[c] = 1;
      else
        amap[c] = amap[c] + 1;
    cout << "Characters with maximum occurences: ";
    int max = 0;
    for (auto kv : amap)
      if (kv.second > max)
        max = kv.second;
    for (auto kv : amap)
      if (kv.second == max)
        cout << kv.first << " ";
    cout << endl;
    cout << "Enter text: ";
    getline(cin, s);
  }

  cout << "Occurences for each character: " << endl;
  for (auto kv : amap)
    cout << kv.first << " " << kv.second << endl;
}
