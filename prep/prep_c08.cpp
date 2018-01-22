#include "..//lab08//dijkstra.hpp"
#include <iostream>

using namespace std;

int main() {
  // sample of an undirected weighted graph with 4 vertices and 5 edges
  // A 2,B 6,C
  // B 2,A 3,C 1,D
  // C 6,A 3,B 7,D
  // D 1,B 7,C

  map<string, vector<pair<int, string>>> graph;
  vector<pair<int, string>> va = {{2, "B"}, {6, "C"}};
  graph["A"] = va;
  // alternate vertex and edge creation for vertex A
  // vector<pair<int, string>> va;
  // vd.push_back(make_pair(2, "B"));
  // vd.push_back(make_pair(6, "C"));
  // graph["A"] = va;
  vector<pair<int, string>> vb = {{2, "A"}, {3, "C"}, {1, "D"}};
  graph["B"] = vb;
  vector<pair<int, string>> vc = {{6, "A"}, {3, "B"}, {7, "D"}};
  graph["C"] = vc;
  vector<pair<int, string>> vd = {{1, "B"}, {7, "C"}};
  graph["D"] = vd;

  map<string, path_info> shortest_path_distances;
  string source = "A";
  compute_shortest_paths_to_all_vertices(graph, source,
                                         shortest_path_distances);
  for (auto p : shortest_path_distances) {
    cout << "Shortest path from vertex " << source << " to vertex " << p.first
         << " is {" << p.second.path << "} having length " << p.second.cost
         << endl;
  }
}
