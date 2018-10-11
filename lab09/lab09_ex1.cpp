#include "binary_tree.hpp"
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<string> previous_nodes) {
  for (string s : previous_nodes) {
    cout << s << " ";
  }
  cout << endl;
}

void print_tree(node *root_node, vector<string> previous_nodes) {
  if (root_node == NULL) {
    print_vector(previous_nodes);
  } else {
    // cout << "call root node=" << root_node->key << " path=";
    // print_vector(previous_nodes);
    previous_nodes.push_back(root_node->key);
    if (root_node->left == NULL && root_node->right == NULL) {
      print_vector(previous_nodes);
    } else {
      if (root_node->left != NULL)
        print_tree(root_node->left, previous_nodes);
      if (root_node->right != NULL)
        print_tree(root_node->right, previous_nodes);
    }
  }
}

int main() {
  node *root_node = NULL;
  vector<string> v = {"A", "B", "C", "D", "E", "F", "G", "H"};
  for (string x : v) {
    if (root_node == NULL)
      root_node = insert(root_node, x);
    else
      insert(root_node, x);
  }

  cout << "Level-order Traversal ";
  print_level_order(root_node);
  cout << endl;

  vector<string> path;
  print_tree(root_node, path);
}
