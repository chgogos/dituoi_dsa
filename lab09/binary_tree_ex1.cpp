#include "binary_tree.hpp"
#include <iostream>
#include <vector>
using namespace std;

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
  cout << "Pre-order Traversal   ";
  print_pre_order(root_node);
  cout << endl;
  cout << "In-order Traversal    ";
  print_in_order(root_node);
  cout << endl;
  cout << "Post-order Traversal  ";
  print_post_order(root_node);
  cout << endl;
}
