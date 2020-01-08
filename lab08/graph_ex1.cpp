#include "graph.hpp"

using namespace std;

int main() {
  string fn("graph1.txt"); 
  w_graph graph = read_data(fn);
  print_graph(graph);
  return 0;
}