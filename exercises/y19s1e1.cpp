#include <iostream>
#include <random>
#include <ctime>
#define N 100

using namespace std;

void fun(int a[], double &avg, int &min, int &max)
{
    avg = a[0];
    min = a[0];
    max = a[0];
    for (int i = 0; i < N; i++)
    {
        avg += a[i];
        if (a[i]> max)
            max= a[i];
        if (a[i]< min)
            min = a[i];
    }
    avg /= N;
}

int main()
{
    int a[N];
    int min, max;
    double avg;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        a[i] = rand() % 1001;
        cout << a[i] << endl;
    }

    fun(a, avg, min, max);
    cout << "Average: " << avg << " min: " << min << " max: " << max << endl;
}