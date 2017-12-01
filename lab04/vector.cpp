#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector<int> v1{10, 20, 30, 40};
  cout << "1. The first element is " << v1.front() << endl;
  cout << "2. The first element is " << v1[0] << endl;
  cout << "3. The first element is " << v1.at(0) << endl;
  cout << "4. The first element is " << *(v1.begin()) << endl;
  cout << "1. The last element is " << v1.back() << endl;
  cout << "2. The last element is " << v1[3] << endl;
  cout << "3. The last element is " << v1.at(3) << endl;
  cout << "4. The last element is " << *(v1.end() - 1) << endl;

  vector<int> v2{10, 20, 30, 40};
  if (v1 == v2)
    cout << "equal vectors" << endl;
}