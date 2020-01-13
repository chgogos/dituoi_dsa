#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[100];
    for (int i = 0; i < 100; i++)
        a[i] = 100 - i;
    sort(begin(a), end(a));
    int x;
    cin >> x;
    if (x >= 1 && x <= 100)
    {
        int pos = x - 1;
        for (int i = pos; i < 100; i++)
            a[i] = a[i + 1];
        a[99] = -1;
    }
    for (int i = 0; i < 100; i++)
        cout << a[i] << " ";
    cout << endl;
}