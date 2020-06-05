#include "quick_sort.cpp"
#include <iostream>

using namespace std;
int main(){
    int a[] = {7,2,3,8,9,10,11,6};
    int p = partition(a, 0, 7);
    cout << p << endl;
    for(int i=0;i<sizeof(a)/sizeof(int);i++)
        cout << a[i] << " ";
    cout << endl;
}