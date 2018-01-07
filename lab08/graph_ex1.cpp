#include "graph.hpp"

using namespace std;

int main() {
  map<string, vector<pair<int, string>>> graph = read_data("graph1.txt");
  print_graph(graph);
  return 0;
}