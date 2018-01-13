#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

map<string, vector<pair<int, string>>> read_data(string fn);
void print_graph(map<string, vector<pair<int, string>>> &g);