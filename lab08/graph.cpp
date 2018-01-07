#include "graph.hpp"

using namespace std;

map<string, vector<pair<int, string>>> read_data(string fn) {
  map<string, vector<pair<int, string>>> graph;
  fstream filestr;
  string buffer;
  filestr.open(fn.c_str());
  if (filestr.is_open())
    while (getline(filestr, buffer)) {
      string buffer2;
      stringstream ss;
      ss.str(buffer);
      vector<string> tokens;
      while (ss >> buffer2)
        tokens.push_back(buffer2);
      string vertex1 = tokens[0].c_str();
      for (size_t i = 1; i < tokens.size(); i++) {
        int pos = tokens[i].find(",");
        int weight = atoi(tokens[i].substr(0, pos).c_str());
        string vertex2 =
            tokens[i].substr(pos + 1, tokens[i].length() - 1).c_str();
        graph[vertex1].push_back(make_pair(weight, vertex2));
      }
    }
  else {
    cout << "Error opening file: " << fn << endl;
    exit(-1);
  }
  return graph;
}

void print_graph(map<string, vector<pair<int, string>>> &g) {
  for (const auto &p1 : g) {
    for (const auto &p2 : p1.second)
      cout << p1.first << "<--" << p2.first << "-->" << p2.second << " ";
    cout << endl;
  }
}
