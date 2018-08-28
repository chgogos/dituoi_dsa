#include "binary_tree.hpp"
#include <queue>
#include <iostream>
using namespace std;

node* insert(node *root_node, string key)
{
    if (root_node == NULL)
    {
        cout << "key " << key << " inserted (root of the tree)" << endl;
        return new node{key, NULL, NULL};
    }
    else
    {
        queue<node *> q;
        q.push(root_node);
        while (!q.empty())
        {
            node *anode = q.front();
            q.pop();
            if (anode->left != NULL && anode->right != NULL)
            {
                q.push(anode->left);
                q.push(anode->right);
            }
            else
            {
                if (anode->left == NULL)
                {
                    anode->left = new node{key, NULL, NULL};
                }
                else
                {
                    anode->right = new node{key, NULL, NULL};
                }
                cout << "key " << key << " inserted" << endl;
                return anode;
            }
        }
    }
    return NULL; 
}

void print_level_order(node *root_node)
{
    if (root_node == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root_node);
    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        cout << node->key << " ";
        if (node->left != NULL)
        {
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            q.push(node->right);
        }
    }
}

void print_pre_order(node *root_node)
{
    if (root_node != NULL)
    {
        cout << root_node->key << " ";
        if (root_node->left != NULL)
        {
            print_pre_order(root_node->left);
        }
        if (root_node->right != NULL)
        {
            print_pre_order(root_node->right);
        }
    }
    else
    {
        cout << "EMPTY";
    }
}

void print_in_order(node *root_node)
{
    if (root_node != NULL)
    {
        if (root_node->left != NULL)
        {
            print_in_order(root_node->left);
        }
        cout << root_node->key << " ";
        if (root_node->right != NULL)
        {
            print_in_order(root_node->right);
        }
    }
    else
    {
        cout << "EMPTY";
    }
}

void print_post_order(node *root_node)
{
    if (root_node != NULL)
    {
        if (root_node->left != NULL)
        {
            print_post_order(root_node->left);
        }
        if (root_node->right != NULL)
        {
            print_post_order(root_node->right);
        }
        cout << root_node->key << " ";
    }
    else
    {
        cout << "EMPTY";
    }
}

void destroy(node *root_node)
{
    if (root_node != NULL)
    {
        destroy(root_node->left);
        destroy(root_node->right);
        delete root_node;
    }
}
