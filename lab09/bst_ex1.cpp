#include "bst.hpp"
#include <vector>
using namespace std;

void test_search(node *root_node, int key)
{
    cout << "Searching for key " << key << ": ";
    node *p = search(root_node, key);
    if (p != NULL)
    {
        cout << "found (" << p->key << ")" << endl;
    }
    else
    {
        cout << "not found " << endl;
    }
}

void test_min_max(node *root_node)
{
    cout << "Minimum " << min(root_node)->key << " Maximum " << max(root_node)->key << endl;
}

int main()
{
    node *root_node = NULL;
    vector<int> v = {10, 6, 5, 8, 14, 11, 18};
    for (int x : v)
    {
        if (root_node == NULL)
        {
            root_node = insert(root_node, x);
        }
        else
        {
            insert(root_node, x);
        }
    }
    cout << "In-order Traversal ";
    print_in_order(root_node);
    cout << endl;
    test_search(root_node, 11);
    test_search(root_node, 13);
    test_min_max(root_node);
    cout << "Remove node 10 ";
    root_node = remove(root_node, 10);
    cout << endl << "In-order Traversal ";
    print_in_order(root_node);
    cout << endl;
    destroy(root_node);
}
