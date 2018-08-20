#include "bst.hpp"

using namespace std;

node *insert(node *tree, int key)
{
    if (tree == NULL)
    {
        node *new_tree = new node;
        new_tree->left = NULL;
        new_tree->right = NULL;
        new_tree->key = key;
        return new_tree;
    }
    if (key < tree->key)
    {
        tree->left = insert(tree->left, key);
    }
    else
    {
        tree->right = insert(tree->right, key);
    }
    return tree;
}

node *search(node *tree, int key)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->key == key)
    {
        return tree;
    }
    else if (key < tree->key)
    {
        return search(tree->left, key);
    }
    else
    {
        return search(tree->right, key);
    }
}

node *remove(node *tree, int key)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->key == key)
    {
        if (tree->left == NULL)
        {
            node *right_subtree = tree->right;
            delete tree;
            return right_subtree;
        }
        if (tree->right == NULL)
        {
            node *left_subtree = tree->left;
            delete tree;
            return left_subtree;
        }
        node *max_node = max(tree->left);
        max_node->left = remove_max_node(tree->left, max_node);
        max_node->right = tree->right;
        delete tree;
        return max_node;
    }
    else if (tree->key > key)
    {
        tree->left = remove(tree->left, key);
    }
    else
    {
        tree->right = remove(tree->right, key);
    }
    return tree;
}

void destroy(node *tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

node *max(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->right == NULL)
    {
        return tree;
    }
    return max(tree->right);
}

node *remove_max_node(node *tree, node *max_node_tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree == max_node_tree)
    {
        return max_node_tree->left;
    }
    tree->right = remove_max_node(tree->right, max_node_tree);
    return tree;
}

node *min(node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->left == NULL)
    {
        return tree;
    }
    return min(tree->left);
}


void print_in_order(node *tree)
{
    if (tree != NULL)
    {
        if (tree->left != NULL)
        {
            print_in_order(tree->left);
        }
        cout << tree->key << " ";
        if (tree->right != NULL)
        {
            print_in_order(tree->right);
        }
    }
    else
    {
        cout << "EMPTY";
    }
}
