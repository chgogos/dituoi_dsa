#include "bst.hpp"
#include <vector>
using namespace std;

void test_search(node *tree, int key)
{
    cout << "Searching for key " << key << ": ";
    node *p = search(tree, key);
    if (p != NULL)
    {
        cout << "found (" << p->key << ")" << endl;
    }
    else
    {
        cout << "not found " << endl;
    }
}

void test_min_max(node *tree)
{
    cout << "Minimum " << min(tree)->key << " Maximum " << max(tree)->key << endl;
}

int main()
{
    node *tree = NULL;
    vector<int> v = {10, 6, 5, 8, 14, 11, 18};
    for (int x : v)
    {
        if (tree == NULL)
        {
            tree = insert(tree, x);
        }
        else
        {
            insert(tree, x);
        }
    }
    cout << "In-order Traversal ";
    print_in_order(tree);
    cout << endl;
    test_search(tree, 11);
    test_search(tree, 13);
    test_min_max(tree);
    destroy(tree);
}
