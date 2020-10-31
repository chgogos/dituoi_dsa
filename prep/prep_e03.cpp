#include <iostream>

// Quiz MSTEAMS 9/6/2020

using namespace std;

struct node
{
    int value;
    node *next = NULL;
    node *prev = NULL;
};
int main()
{
    node n1, n2, n3, n4;
    n1.value = 12;n1.next = &n2;
    n2.value = 99;n2.next = &n3;n2.prev = &n1;
    n3.value = 37;n3.next = &n4;n3.prev = &n2;
    n4.value = 42;n4.prev = &n3;
    node *head = &n1;
    node *tail = &n4;
    cout << head->next->next->value;
    cout << tail->prev->prev->value;
}

/*
3799
*/