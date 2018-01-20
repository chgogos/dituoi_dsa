#include <climits>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct path_info {
  string path;
  int cost;
};

void compute_shortest_paths_to_all_vertices(
    map<string, vector<pair<int, string>>> &graph, string source,
    map<string, path_info> &shortest_path_distances);
