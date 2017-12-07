/**
 * https://codefights.com/interview-practice/topics/heaps-stacks-queues
 */

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

string simplifyPath(string path) {
  stringstream test(path);
  stack<string> dir_stack;
  string segment;
  while (getline(test, segment, '/')) {
    if (segment == "..") {
      if (!dir_stack.empty())
        dir_stack.pop();
    } else if (segment != "." && segment != "")
      dir_stack.push(segment);
  }
  string output;
  while (!dir_stack.empty()) {
    if (output == "")
      output = dir_stack.top();
    else
      output = dir_stack.top() + "/" + output;
    dir_stack.pop();
  }
  return "/" + output;
}

int main() {
  string s = "/home/a//./x/..";
  // string s = "/../";
  cout << simplifyPath(s) << endl;
}