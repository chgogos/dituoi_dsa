#include "binary_search.cpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int key, a[] = {11, 45, 53, 60, 67, 72, 88, 91, 94, 98}, N = sizeof(a) / sizeof(int);
	for (int i = 0; i < N; i++)
		cout << "a[" << i << "]=" << a[i] << " ";
	cout << endl;
	cout << "Search for: ";
	cin >> key;
	cout << "Using non recursive algorithm (binary search)" << endl;
	int pos = binary_search(a, N, key);
	if (pos == -1)
		cout << "Not found" << endl;
	else
		cout << "Found at position " << pos << endl;

	cout << "Using recursive algorithm (binary search)" << endl;
	pos = binary_search_r(a, N, key);
	if (pos == -1)
		cout << "Not found" << endl;
	else
		cout << "Found at position " << pos << endl;
}
