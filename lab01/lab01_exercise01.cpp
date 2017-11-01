#include <bits/stdc++.h>

// http://www.geeksforgeeks.org/bitsstdc-h-c/

using namespace std;

void func(int a[], int N, double &avg, int &c) {
  double sum = 0.0;
  for (int i = 0; i < N; i++)
  sum += a[i];
  avg = sum / N;
  for (int i = 0; i < N; i++)
    if (a[i] >= 0.9 * avg && a[i] <= 1.1 * avg)
      c++;
}

int main(void) {
  int a[100], c;
  double avg;
  srand(12345);
  for (int i = 0; i < 100; i++)
    a[i] = rand() % 100 + 1;
  func(a, 100, avg, c);
  cout << "Average: " << avg << " count: " << c << endl;
}