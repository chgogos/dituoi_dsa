#include "insertion_sort.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct student {
  string name;
  int grade;
  bool operator<(student other) const { return grade > other.grade; }
};

void print_students(student a[], int N) {
  for (int i = 0; i < N; i++)
    cout << a[i].name << "-" << a[i].grade << " ";
  cout << endl;
}

int main(void) {
  vector<student> v;
  fstream filestr;
  string buffer;

  filestr.open("students20.txt");
  if (!filestr.is_open()) {
    cerr << "File not found" << endl;
    exit(-1);
  }
  while (getline(filestr, buffer)) {
    stringstream ss(buffer);
    student st;
    ss >> st.name;
    ss >> st.grade;
    v.push_back(st);
  }
  filestr.close();

  int N = v.size();
  cout << "ORIGINAL LIST:" << endl;
  for (int i = 0; i < N; i++)
    cout << v[i].name << "-" << v[i].grade << " ";
  cout << endl;

  cout << "INSERTION SORT: (STABLE)" << endl;
  student *a = new student[N];
  for (int i = 0; i < N; i++)
    a[i] = v[i];
  insertion_sort(a, N);
  print_students(a, N);
  delete[] a;

  cout << "MERGE SORT: (NON STABLE)" << endl;
  a = new student[N];
  for (int i = 0; i < N; i++)
    a[i] = v[i];
  merge_sort(a, N);
  print_students(a, N);
  delete[] a;

  cout << "QUICK SORT: (NON STABLE)" << endl;
  a = new student[N];
  for (int i = 0; i < N; i++)
    a[i] = v[i];
  quick_sort(a, N);
  print_students(a, N);
  delete[] a;

  cout << "STL SORT: (NON STABLE)" << endl;
  a = new student[N];
  for (int i = 0; i < N; i++)
    a[i] = v[i];
  sort(a, a + N);
  print_students(a, N);
  delete[] a;

  cout << "STL STABLESORT: (STABLE)" << endl;
  a = new student[N];
  for (int i = 0; i < N; i++)
    a[i] = v[i];
  stable_sort(a, a + N);
  print_students(a, N);
  delete[] a;
}
