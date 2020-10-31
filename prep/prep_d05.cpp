#include <iostream>
#include <list>
#define N 5

using namespace std;

struct node
{
    string name;
    string phone;
    struct node *next;
};

int main()
{
    string names[] = {"nikos", "petros", "maria", "kostas", "anna"};
    string phones[] = {"6977123456", "6977234567", "6977345678", "6977456789", "6977567890"};

    // part A
    cout << "Linked List" << endl;

    // Δημιουργία πρώτου κόμβου της λίστας με τα στοιχεία της πρώτης επαφής
    node *head = new node;
    head->name = names[0];
    head->phone = phones[0];
    head->next = NULL;

    // Προσθήκη στο τέλος της λίστας των υπόλοιπων επαφών
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

    // Διάσχιση της λίστας και εμφάνιση όλων των επαφών
    for (node *curr = head; curr != NULL; curr = curr->next)
        cout << curr->name << " " << curr->phone << endl;

    // Διαγραφή της μνήμης που καταλαμβάνει η λίστα
    curr = head;
    while (curr != NULL)
    {
        node *copy = curr;
        curr = curr->next;
        delete copy;
    }

    // part B
    cout << "STL Linked List" << endl;
    struct contact
    {
        string name;
        string phone;
    };
    // Δήλωση της λίστας
    list<contact> a_list;

    // Προσθήκη των επαφών στη λίστα
    for (int i = 0; i < N; i++)
        a_list.push_back({names[i], phones[i]});

    // Διάσχιση της λίστας και εμφάνιση όλων των επαφών
    for (auto c : a_list)
        cout << c.name << " " << c.phone << endl;
}

/*
Linked List
nikos 6977123456
petros 6977234567
maria 6977345678
kostas 6977456789
anna 6977567890
STL Linked List
nikos 6977123456
petros 6977234567
maria 6977345678
kostas 6977456789
anna 6977567890
*/