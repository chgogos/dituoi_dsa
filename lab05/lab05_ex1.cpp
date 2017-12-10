#include <iostream>
#include <stack>

using namespace std;
// examples of palindromic sentences:
// SOFOS, A MAN A PLAN A CANAL PANAMA, AMORE ROMA, LIVE NOT ON EVIL
int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage examples: " << endl;
    cerr << "\t\t " << argv[0] << " SOFOS" << endl;
    cerr << "\t\t " << argv[0] << " \"A MAN A PLAN A CANAL PANAMA\"" << endl;
    exit(-1);
  }
  string str = argv[1];
  stack<char> astack;
  string str1;
  for (char c : str)
    if (c != ' ') {
      str1 += c;
      astack.push(c);
    }
  string str2;
  while (!astack.empty()) {
    str2 += astack.top();
    astack.pop();
  }
  if (str1 == str2)
    cout << "The sentence " << str << " is palindromic." << endl;
  else
    cout << "The string " << str << " is not palindromic." << endl;
}
