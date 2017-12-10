#include <iostream>
#include <stack>
#include <string> // stoi

using namespace std;
int main() {
  string bs;
  stack<int> astack;
  cout << "Enter a binary number: ";
  cin >> bs;
  for (char c : bs) {
    if (c != '0' && c != '1') {
      cerr << "use only digits 0 and 1" << endl;
      exit(-1);
    }
    astack.push(c - '0');
  }

  int sum = 0, x = 1;
  while (!astack.empty()) {
    sum += astack.top() * x;
    astack.pop();
    x *= 2;
  }
  cout << "Decimal: " << sum << endl;

  cout << "Decimal: " << stoi(bs, nullptr, 2); // one line solution :)
}