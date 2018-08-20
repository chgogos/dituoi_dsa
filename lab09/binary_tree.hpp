#include <cstddef>

struct node {
    int key;
    node *left;
    node *right;
};

void insert(node *&root_node, int key);
void print_level_order(node *root_node);
void print_pre_order(node *root_node);
void destroy(node *root_node);
void print_in_order(node *root_node);
void print_post_order(node *root_node);
