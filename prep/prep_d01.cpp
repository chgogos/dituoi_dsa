#include <iostream>
using namespace std;

void fun(int a[][3], int i, int &sum, int &min)
{
    sum = 0;
    for (int j = 0; j < 3; j++)
    {
        min = a[i][0];
        if (a[i][j] < min)
            min = a[i][j];
        sum += a[i][j];
    }
}

int main()
{
    int a[][3] = {{1, 10, 7}, {3, 2, 5}, {8, 6, 7}, {0, 2, 8}};
    int sum;
    int min;
    fun(a, 1, sum, min);
    cout << "Min=" << min << " Sum=" << sum << endl;
}