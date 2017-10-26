#include <iostream>
#include <vector>

using namespace std;

void print_vector(const string &name, const vector<int> &v) {
  cout << name << ": ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

int main(int argc, char *argv[]) {
  vector<int> v1;
  v1.push_back(5);
  v1.push_back(16);
  print_vector("v1", v1);

  vector<int> v2 = {16, 3, 6, 1, 9, 10};
  print_vector("v2", v2);

  vector<int> v3{5, 2, 10, 1, 8};
  print_vector("v3", v3);

  vector<int> v4(5, 10);
  print_vector("v4", v4);

  vector<int> v5(v2);
  print_vector("v5", v5);

  vector<int> v6(v2.begin() + 1, v2.end() - 1);
  print_vector("v6", v6);
}
