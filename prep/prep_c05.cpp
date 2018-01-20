#include "..//lab08//graph.hpp"

using namespace std;

int main() {
  map<string, vector<pair<int, string>>> graph =
      read_data("..//lab08//graph1.txt");
  int max = 0;
  for (auto kv : graph) {
    cout << kv.first << " " << kv.second.size() << endl;
    if (kv.second.size() > max)
      max = kv.second.size();
  }

  cout << "Max degree=" << max << ", vertices having max degree: ";
  for (auto kv : graph)
    if (kv.second.size() == max)
      cout << kv.first << " ";
  cout << endl;
}