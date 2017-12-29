#include <algorithm>
#include <bitset>
#include <chrono>
#include <iostream>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

// number of items in the set
constexpr int N = 1000;
// number of values checked whether they exist in the set
constexpr int M = 5E6;
// number of bits of the bitset
constexpr int BS_SIZE = 10001;
uniform_int_distribution<uint32_t> dist(0, 1E5);

void scenario1(vector<uint32_t> &avector) {
  long seed = 1940;
  mt19937 mt(seed);
  int c = 0;
  for (int i = 0; i < M; i++)
    if (find(avector.begin(), avector.end(), dist(mt)) == avector.end())
      c++;
  cout << "Values not in the set (using unsorted vector): " << c << " ";
}

void scenario2(vector<uint32_t> &avector) {
  sort(avector.begin(), avector.end());
  long seed = 1940;
  mt19937 mt(seed);
  int c = 0;
  for (int i = 0; i < M; i++)
    if (!binary_search(avector.begin(), avector.end(), dist(mt)))
      c++;
  cout << "Values not in the set (using sorted vector): " << c << " ";
}

void scenario3(set<uint32_t> &aset) {
  long seed = 1940;
  mt19937 mt(seed);
  int c = 0;
  for (int i = 0; i < M; i++)
    if (aset.find(dist(mt)) == aset.end())
      c++;
  cout << "Values not in the set (using std::set): " << c << " ";
}

void scenario4(unordered_set<uint32_t> &auset) {
  long seed = 1940;
  mt19937 mt(seed);
  int c = 0;
  for (int i = 0; i < M; i++)
    if (auset.find(dist(mt)) == auset.end())
      c++;
  cout << "Values not in the set (using std::unordered_set): " << c << " ";
}

inline uint32_t hash1(uint32_t x) { return x; }
inline uint32_t hash2(uint32_t x) { return 3 * x; }
inline uint32_t hash3(uint32_t x) { return 5 * x + 7; }

void scenario5(bitset<BS_SIZE> &bs, unordered_set<uint32_t> &aset) {
  long seed = 1940;
  mt19937 mt(seed);
  int c = 0;
  for (int i = 0; i < M; i++) {
    uint32_t x = dist(mt), h1 = hash1(x), h2 = hash2(x), h3 = hash3(x);
    if (!bs.test(h1 % BS_SIZE) || !bs.test(h2 % BS_SIZE) ||
        !bs.test(h3 % BS_SIZE) || aset.find(x) == aset.end())
      c++;
  }
  cout << "Values not in the set (using bloom filter + std::unordered_set): "
       << c << " ";
}

int main() {
  long seed = 1821;
  mt19937 mt(seed);
  high_resolution_clock::time_point t1, t2;
  duration<double, std::micro> duration_micro;
  vector<uint32_t> avector(N);
  // fill vector with random values using std::generate and lambda function
  std::generate(avector.begin(), avector.end(), [&mt]() { return dist(mt); });

  t1 = high_resolution_clock::now();
  scenario1(avector);
  t2 = high_resolution_clock::now();
  duration_micro = t2 - t1;
  cout << "elapsed time: " << duration_micro.count() << " microseconds, "
       << duration_micro.count() / 1E6 << " seconds" << endl;

  t1 = high_resolution_clock::now();
  scenario2(avector);
  t2 = high_resolution_clock::now();
  duration_micro = t2 - t1;
  cout << "elapsed time: " << duration_micro.count() << " microseconds, "
       << duration_micro.count() / 1E6 << " seconds" << endl;

  set<uint32_t> aset(avector.begin(), avector.end());
  t1 = high_resolution_clock::now();
  scenario3(aset);
  t2 = high_resolution_clock::now();
  duration_micro = t2 - t1;
  cout << "elapsed time: " << duration_micro.count() << " microseconds, "
       << duration_micro.count() / 1E6 << " seconds" << endl;

  unordered_set<uint32_t> auset(avector.begin(), avector.end());
  t1 = high_resolution_clock::now();
  scenario4(auset);
  t2 = high_resolution_clock::now();
  duration_micro = t2 - t1;
  cout << "elapsed time: " << duration_micro.count() << " microseconds, "
       << duration_micro.count() / 1E6 << " seconds" << endl;

  bitset<BS_SIZE> bs;
  for (int x : avector) {
    bs.set(hash1(x) % BS_SIZE, true);
    bs.set(hash2(x) % BS_SIZE, true);
    bs.set(hash3(x) % BS_SIZE, true);
  }
  t1 = high_resolution_clock::now();
  scenario5(bs, auset);
  t2 = high_resolution_clock::now();
  duration_micro = t2 - t1;
  cout << "elapsed time: " << duration_micro.count() << " microseconds, "
       << duration_micro.count() / 1E6 << " seconds" << endl;
}
