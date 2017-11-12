#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  auto f = [](double x, double y) { return (y - x) / x; };
  vector<double> v = {3.1, 3.3, 3.4, 5.5, 6.1};
  for (int i = 1; i < v.size(); i++)
    cout << v[i - 1] << " " << v[i] << " --> " << f(v[i - 1], v[i]) * 100 << "%"
         << endl;
}