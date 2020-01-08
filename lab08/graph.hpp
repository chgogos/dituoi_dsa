#ifndef GRAPH_HPP
#define GRAPH_HPP 

#include <map>
#include <utility>
#include <vector>
#include <string>

using namespace std;

typedef map<string, vector<pair<int, string>>> w_graph;

w_graph read_data(string fn);

void print_graph(w_graph &g);

#endif