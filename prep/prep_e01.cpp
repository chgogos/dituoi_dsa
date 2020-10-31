// Quiz MSTEAMS 9/6/2020

#include <iostream>
using namespace std;


int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;
    p++;
    (*p)++;
    p += 2;
    (*p) += 2;
    for (int i = 0; i < 5; i++)
        cout << a[i];
}

/*
13365
*/