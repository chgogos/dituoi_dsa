#include <forward_list>
#include <iostream>

using namespace std;
int main() {
  forward_list<int> fl{10, 20, 30, 40, 50};
  for (int x : fl)
    cout << x << " ";
  cout << endl;
  fl.reverse();
  for (int x : fl)
    cout << x << " ";
  cout << endl;
}
