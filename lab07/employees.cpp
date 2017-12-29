#include <random>
using namespace std;

mt19937 mt(1821);
uniform_int_distribution<int> uni(0, 25);

struct employee {
  string name;
  string address;
};

string generate_random_string(int k) {
  string s{};
  const string letters_en = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < k; i++)
    s += letters_en[uni(mt)];
  return s;
}