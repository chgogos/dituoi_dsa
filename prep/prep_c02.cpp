#include <iostream>

using namespace std;

struct student {
  string name;
  string address;
};

size_t my_hash(struct student &student) {
  string s = student.name + student.address;
  size_t sum = 0;
  for (char c : s)
    sum += c;
  return sum;
}

int main() {
  student s1{"nikos", "korinthou 253"};
  student *s2 = new student();
  s2->name = "christos";
  s2->address = "amerikis 5";

  cout << "hash:" << my_hash(s1) << endl;
  cout << "hash:" << my_hash(*s2) << endl;
  delete s2;
}
