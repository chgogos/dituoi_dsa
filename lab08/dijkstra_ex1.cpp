#include "dijkstra.hpp"
#include "graph.hpp"

using namespace std;

int main() {
  map<string, vector<pair<int, string>>> graph = read_data("graph1.txt");
  map<string, pair<string, int>> shortest_path_distances;
  string source = "A";
  compute_shortest_paths_to_all_vertices(graph, source,
                                         shortest_path_distances);
  for (auto p : shortest_path_distances){
    cout << "Shortest path from vertex " << source << " to vertex "
         << p.first << " is {" << p.second.first << "} having length " 
         << p.second.second << endl;
  }
}
