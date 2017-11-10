#include <iostream>

using namespace std;

struct student {
  string name;
  double vathmos;
};

template <class T> void swapo(T &x, T &y) {
  T temp;
  temp = x;
  x = y;
  y = temp;
}

int main(void) {
  student st1 = {"nikos", 5.5};
  student st2 = {"maria", 7.5};
  cout << "BEFORE:" << endl;
  cout << st1.name << "-" << st1.vathmos << endl;
  cout << st2.name << "-" << st2.vathmos << endl;
  swapo(st1, st2);
  cout << "AFTER:" << endl;
  cout << st1.name << "-" << st1.vathmos << endl;
  cout << st2.name << "-" << st2.vathmos << endl;
}