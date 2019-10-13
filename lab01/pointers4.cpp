#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int *p = new int;
    *p = 2;
    (*p)++;
    cout << "Value in p: " << p << " dereference p: " << *p << endl;
    delete p;
    return 0;
}