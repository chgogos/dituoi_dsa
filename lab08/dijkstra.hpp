#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <map>
#include <string>
#include <vector>
#include "graph.hpp"

using namespace std;

struct path_info
{
  string path;
  int cost;
};

void compute_shortest_paths_to_all_vertices(
    w_graph &graph, string source,
    map<string, path_info> &shortest_path_distances);

#endif