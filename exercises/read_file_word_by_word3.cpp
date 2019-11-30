#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ανάγνωση δεδομένων και εισαγωγή σε vector
    FILE *fp = freopen("1984_small.txt", "r", stdin);
    if (fp == NULL)
    {
        cerr << "File problem" << endl;
        exit(-1);
    }
    vector<string> words;
    string w;
    while (cin >> w)
    {
        words.push_back(w);
    }

    // εμφάνιση περιεχομένων vector
    for (string w : words)
    {
        cout << w << " ";
    }
}
