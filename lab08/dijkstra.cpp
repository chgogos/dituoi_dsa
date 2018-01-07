#include "dijkstra.hpp"

using namespace std;

void compute_shortest_paths_to_all_vertices(
    map<string, vector<pair<int, string>>> &graph, string source,
    map<string, int> &shortest_path_distances) {
  vector<string> S{source};
  set<string> NS;
  for (auto &kv : graph)
    if (kv.first == source)
      shortest_path_distances[kv.first] = 0;
    else {
      NS.insert(kv.first);
      shortest_path_distances[kv.first] = INT_MAX;
    }

  while (!NS.empty()) {
    string v1 = S.back();
    for (pair<int, string> w_v : graph[v1]) {
      int weight = w_v.first;
      string v2 = w_v.second;
      if (NS.find(v2) != NS.end())
        if (shortest_path_distances[v1] + weight < shortest_path_distances[v2])
          shortest_path_distances[v2] = shortest_path_distances[v1] + weight;
    }
    int min = INT_MAX;
    string pmin = "None";
    for (string v2 : NS) {
      if (shortest_path_distances[v2] < min) {
        min = shortest_path_distances[v2];
        pmin = v2;
      }
    }
    // in case the graph is not connected
    if (pmin == "None")
      break;
    S.push_back(pmin);
    NS.erase(pmin);
  }
}
