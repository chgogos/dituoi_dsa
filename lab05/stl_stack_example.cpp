#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;
int main(void) {
  cout << "std::stack example" << endl;
  stack<char> items; // adaptor over a deque container
  // stack<char, deque<char>> items; // adaptor over a deque container
  // stack<char, vector<char>> items; // adaptor over a vector container
  // stack<char, list<char>> items; // adaptor over a list container

  for (char c = 65; c < 65 + 26; c++) {
    cout << c << " ";
    items.push(c);
  }
  cout << endl;

  while (!items.empty()) {
    cout << items.top() << " ";
    items.pop();
  }
  cout << endl;
}
