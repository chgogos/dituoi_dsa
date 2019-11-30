// ο κώδικας υπολογίζει την έλάχιστη τιμή αντί για τη μέγιστη.
#include <iostream>

using namespace std;

int main()
{
    int a[] = {12, 96, 11, 72, 78};
    int max = a[0];
    for (int i = 1; i < 5; i++)
    {
        if (a[i] < max)
        {
            max = a[i];
        }
    }
    cout << "maximum value: " << max << endl;
}
