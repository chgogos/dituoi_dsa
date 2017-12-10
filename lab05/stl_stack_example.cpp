#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;
int main(void) {
  cout << "std::stack example" << endl;
  stack<char> items; // adapter over a vector container
  // stack<char, vector<char>> items; // adapter over a vector container
  // stack<char, list<char>> items; // adapter over a list container
  // stack<char, deque<char>> items; // adapter over a deque container

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
