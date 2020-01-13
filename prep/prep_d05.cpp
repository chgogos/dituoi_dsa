#include <iostream>
#define N 5

using namespace std;

struct node
{
    string name;
    string phone;
    struct node *next;
};

string names[] = {"nikos", "petros", "maria", "kostas", "anna"};
string phones[] = {"111", "222", "333", "444", "555"};

int main()
{
    node *head = new node;
    head->name = names[0];
    head->phone = phones[0];
    head->next = NULL;

    node *curr = head;
    for (int i = 1; i < N; i++)
    {
        node *a_node = new node;
        a_node->name = names[i];
        a_node->phone = phones[i];
        a_node->next = NULL;
        curr->next = a_node;
        curr = a_node;
    }
    
    for (node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->name << " " << curr->phone << endl;

    curr = head;
    while (curr != NULL)
    {
        node *copy = curr;
        curr = curr->next;
        delete copy;
    }
}