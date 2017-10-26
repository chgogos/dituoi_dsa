#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hamming(string x, string y) {
  int c = 0;
  int length = x.size() > y.size() ? x.size() : y.size();
  for (int i = 0; i < length; i++)
    if (x.at(i) != y.at(i))
      c++;
  return c;
}

int main(int argc, char *argv[]) {
  constexpr int N = 100;
  constexpr int L = 20;
  mt19937 mt(1821);
  uniform_int_distribution<int> dist(0, 3);
  char gact[] = {'A', 'G', 'C', 'T'};
  vector<string> sequences(N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < L; j++)
      sequences[i] += gact[dist(mt)];

  int c = 0;
  for (int i = 0; i < N; i++) {
    cout << "Checking sequence: " << sequences[i] << "..." << endl;
    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;
      int hd = hamming(sequences[i], sequences[j]);
      cout << sequences[i] << " " << sequences[j]
           << " ==> hamming distance=" << hd << endl;
      if (hd <= 10) {
        c++;
        break;
      }
    }
    cout << endl;
  }
  cout << "Result=" << c << endl;
}
