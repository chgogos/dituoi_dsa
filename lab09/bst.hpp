#include <cstddef>
#include <iostream>

struct node
{
    int key;
    node *left;
    node *right;
};

node *insert(node *tree, int key);
node *search(node *tree, int key);
node *remove(node *tree, int key);
void destroy(node *tree);
node *max(node *tree);
node *remove_max_node(node *tree, node *max_node);
node *min(node *tree);
void print_in_order(node *tree);
