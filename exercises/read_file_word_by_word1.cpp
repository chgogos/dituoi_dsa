#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    // ανάγνωση δεδομένων και εισαγωγή σε vector
    ifstream infile{"1984_small.txt"};
    if (!infile.good())
    {
        cerr << "File problem" << endl;
        exit(-1);
    }
    vector<string> words;
    string w;
    while (infile >> w)
    {
        words.push_back(w);
    }

    // εμφάνιση περιεχομένων vector
    for (string w : words)
    {
        cout << w << " ";
    }
}