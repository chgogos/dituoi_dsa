#include <climits>
#include <set>
#include "graph.hpp"
#include "dijkstra.hpp"

using namespace std;

void compute_shortest_paths_to_all_vertices(
    w_graph &graph, string source,
    map<string, path_info> &shortest_path_distances)
{
  vector<string> S{source};
  set<string> NS;
  for (auto &kv : graph)
  {
    string path = "";
    if (kv.first == source)
    {
      path += source;
      shortest_path_distances[kv.first] = {path, 0};
    }
    else
    {
      NS.insert(kv.first);
      shortest_path_distances[kv.first] = {path, INT_MAX};
    }
  }

  while (!NS.empty())
  {
    string v1 = S.back();
    for (pair<int, string> w_v : graph[v1])
    {
      int weight = w_v.first;
      string v2 = w_v.second;
      if (NS.find(v2) != NS.end())
        if (shortest_path_distances[v1].cost + weight <
            shortest_path_distances[v2].cost)
        {
          shortest_path_distances[v2].path =
              shortest_path_distances[v1].path + " " + v2;
          shortest_path_distances[v2].cost =
              shortest_path_distances[v1].cost + weight;
        }
    }
    int min = INT_MAX;
    string pmin = "None";
    for (string v2 : NS)
    {
      if (shortest_path_distances[v2].cost < min)
      {
        min = shortest_path_distances[v2].cost;
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
