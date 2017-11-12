#include <iostream>

using namespace std;
struct student {
  string name;
  double vathmos;
};

namespace myfunctions {
template <class T> void swap(T &x, T &y) {
  T temp;
  temp = x;
  x = y;
  y = temp;
}
} // namespace myfunctions

int main(void) {
  cout << "swap integers" << endl;
  int x = 5, y = 7;
  cout << "BEFORE:" << endl;
  cout << "x=" << x << " y=" << y << endl;
  myfunctions::swap(x, y);
  cout << "AFTER:" << endl;
  cout << "x=" << x << " y=" << y << endl;

  cout << "swap records" << endl;
  student st1 = {"nikos", 5.5};
  student st2 = {"maria", 7.5};
  cout << "BEFORE:" << endl;
  cout << "student1=" << st1.name << "-" << st1.vathmos << endl;
  cout << "student2=" << st2.name << "-" << st2.vathmos << endl;
  myfunctions::swap(st1, st2);
  cout << "AFTER:" << endl;
  cout << "student1=" << st1.name << "-" << st1.vathmos << endl;
  cout << "student2=" << st2.name << "-" << st2.vathmos << endl;
}