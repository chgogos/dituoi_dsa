#include "bst.hpp"
#include <vector>
using namespace std;

int is_bst(node *node) {
  if (node == NULL) {
    return true;
  }
  if (node->left != NULL && min(node->left)->key > node->key) {
    return false;
  }
  if (node->right != NULL && max(node->right)->key <= node->key) {
    return false;
  }
  if (!is_bst(node->left) || !is_bst(node->right)) {
    return false;
  }
  return true;
}

int main() {
  node *root_node = NULL;
  vector<int> v = {10, 6, 5, 8, 14, 11, 18};
  for (int x : v) {
    if (root_node == NULL) {
      root_node = insert(root_node, x);
    } else {
      insert(root_node, x);
    }
  }
  cout << (is_bst(root_node) ? "The tree is a BST" : "The tree is not a BST")
       << endl;
  // replacing root node with zero
  root_node->key = 0;
  cout << (is_bst(root_node) ? "The tree is a BST" : "The tree is not a BST")
       << endl;
}
