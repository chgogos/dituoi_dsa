#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  vector<int> v = {23, 13, 31, 17, 56};
  cout << "iteration using index: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;

  cout << "iteration using ranged based for: ";
  for (int x : v)
    cout << x << " ";
  cout << endl;

  cout << "forward iteration with iterator: ";
  vector<int>::iterator iter;
  for (iter = v.begin(); iter != v.end(); iter++)
    cout << *iter << " ";
  cout << endl;

  cout << "backward iteration with iterator: ";
  vector<int>::reverse_iterator riter;
  for (riter = v.rbegin(); riter != v.rend(); riter++)
    cout << *riter << " ";
}
