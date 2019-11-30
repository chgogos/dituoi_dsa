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
    vector<string> words{istream_iterator<string>{infile}, istream_iterator<string>{}};
    
    // εμφάνιση περιεχομένων vector
    for (string w : words)
    {
        cout << w << " ";
    }
}