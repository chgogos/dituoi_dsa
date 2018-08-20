#include "binary_tree.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    node *root_node = NULL;
    vector<int> v = {10, 6, 5, 8, 14, 11, 18};
    for (int x : v)
    {
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
