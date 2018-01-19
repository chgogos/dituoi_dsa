#include <climits>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void compute_shortest_paths_to_all_vertices(
    map<string, vector<pair<int, string>>> &graph, string source,
    map<string, pair<string, int>> &shortest_path_distances);
