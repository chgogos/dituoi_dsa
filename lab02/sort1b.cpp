#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void print(const string &text, const vector<int> &v) {
  cout << text << ": ";
  for (auto it = v.begin(); it < v.end(); it++)
    cout << *it << " ";
  cout << endl;
}

bool comp(int a, int b) { return a > b; }

int main(int argc, char **argv) {
  auto rng = default_random_engine{};
  vector<int> va = {45, 32, 16, 11, 7, 18, 21, 16, 11, 15};
  print("BEFORE      ", va);

  // ascending sort
  sort(va.begin(), va.end());
  print("AFTER (asc) ", va);

  // ascending sort
  shuffle(va.begin(), va.end(), rng);
  print("BEFORE      ", va);
  sort(va.begin(), va.end(), less<int>());
  print("AFTER (asc) ", va);

  // descending sort
  shuffle(va.begin(), va.end(), rng);
  print("BEFORE      ", va);
  sort(va.begin(), va.end(), greater<int>());
  print("AFTER (desc)", va);

  // descending sort
  shuffle(va.begin(), va.end(), rng);
  print("BEFORE      ", va);
  sort(va.begin(), va.end(), [](const int a, const int b) { return a > b; });
  print("AFTER (desc)", va);

  // descending sort
  shuffle(va.begin(), va.end(), rng);
  print("BEFORE      ", va);
  sort(va.begin(), va.end(), comp);
  print("AFTER (desc)", va);
}
