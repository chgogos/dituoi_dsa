#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<int> de;
  for (int i = 1; i <= 20; i++)
    if (i % 2 == 0)
      de.push_front(i);
    else
      de.push_back(i);

  for (int x : de)
    cout << x << " ";
  cout << endl;
}