#include "dijkstra.hpp"
#include "graph.hpp"
#include <algorithm> // max_element
#include <sstream>

using namespace std;

int main() {
  map<string, vector<pair<int, string>>> graph = read_data("graph2.txt");
  for (auto &kv : graph) {
    double sum = 0.0;
    for (auto &p : kv.second) {
      sum += p.first;
    }
    cout << "Vertex " << kv.first << " has degree " << kv.second.size()
         << " and average weighted degree " << sum / kv.second.size() << endl;
  }

  for (auto &kv : graph) {
    string source_vertex = kv.first;
    cout << "Source " << source_vertex << ": ";
    map<string, int> shortest_path_distances;
    compute_shortest_paths_to_all_vertices(graph, source_vertex,
                                           shortest_path_distances);

    vector<int> distances;
    for (auto &p : shortest_path_distances)
      distances.push_back(p.second);
    int max = *(max_element(distances.begin(), distances.end()));

    for (int i = 1; i <= max; i++) {
      stringstream ss;
      ss << "dist=" << i << "->{";
      for (auto &p : shortest_path_distances)
        if (p.second == i)
          ss << p.first << " ";
      ss << "} ";
      string sss = ss.str();
      if (sss.substr(sss.length() - 3) != "{} ") // check for empty list
        cout << sss;
    }
    cout << endl;
  }
}
