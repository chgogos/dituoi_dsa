#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

struct student {
  string name;
  int grade;
};

int main(int argc, char **argv) {
  int N = 10, i = 0;
  student students[10];
  const char *fn = "data_student_struct10.txt";
  fstream filestr;
  string buffer;
  filestr.open(fn);
  if (!filestr.is_open()) {
    cerr << "File not found" << std::endl;
    exit(-1);
  }
  while (getline(filestr, buffer)) {
    stringstream ss(buffer);
    ss >> students[i].name;
    ss >> students[i].grade;
    i++;
  }
  filestr.close();
  double sum = 0.0;
  for (i = 0; i < N; i++)
    sum += students[i].grade;
  double avg = sum / N;
  cout << "Average grade =" << avg / 10.0 << endl;

  double sum2 = 0.0;
  int c = 0;
  for (i = 0; i < N; i++)
    if (students[i].grade > avg) {
      cout << students[i].name << " grade = " << students[i].grade / 10.0
           << endl;
      sum2 += students[i].grade;
      c++;
    }
  double avg2 = sum2 / c;
  cout << "Average grade for students having grade above the average grade = "
       << avg2 / 10.0 << endl;
  return 0;
}
