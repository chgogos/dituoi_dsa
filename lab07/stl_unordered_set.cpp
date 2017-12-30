#include <cctype> // tolower
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  string text = "You can do anything but not everything";
  unordered_set<char> uset;
  for (char c : text)
    if (c != ' ')
      uset.insert(tolower(c));
  cout << "Number of discrete characters=" << uset.size() << endl;
  for (unordered_set<char>::iterator itr = uset.begin(); itr != uset.end();
       itr++)
    cout << *itr << " ";
  cout << endl;
}
