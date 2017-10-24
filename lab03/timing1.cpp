#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  clock_t t1, t2;
  t1 = clock();
  srand(1821);
  double sum = 0.0;
  for (int i = 1; i <= 10000000; i++) {
    int x = rand() % 10000 + 1;
    sum += sqrt(x);
  }
  cout << "The sum is: " << sum << endl;

  t2 = clock();
  double elapsed_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
  cout << "Elapsed time " << elapsed_time << " seconds" << endl;
}
