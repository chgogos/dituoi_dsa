#include <cstddef>
#include <string>

struct node {
    std::string key;
    node *left;
    node *right;
};

node* insert(node *root_node, std::string key);
void print_level_order(node *root_node);
void print_pre_order(node *root_node);
void destroy(node *root_node);
void print_in_order(node *root_node);
void print_post_order(node *root_node);
