#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> alist{10, 20, 30, 40};
  list<int>::iterator it = alist.begin();
  list<int>::reverse_iterator rit = alist.rbegin();

  while (it != alist.end()) {
    cout << "Forwards:" << *it << endl;
    cout << "Backwards:" << *rit << endl;
    it++;
    rit++;
  }
}