#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int x;
  cout << "Enter size of the vector: ";
  cin >> x;
  vector<int> v(x);
  for (int i = 0; i < x; i++)
    v[i] = i;
  v.push_back(99);
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
}
