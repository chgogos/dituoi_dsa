// Quiz MSTEAMS 9/6/2020

#include <iostream>
using namespace std;

int c =0;

int f( int n)
{
    c++;
    if (n <= 1) return n;
    return f(n-1) + f(n-2);
}
int main ()
{
    cout << f(4);
    cout << c;
}

/*
39
*/