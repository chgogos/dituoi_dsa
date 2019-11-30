// Ο κώδικας θα πρέπει να μεταγλωττιστεί με: 
// $ g++ -std=c++11 -O2 -Wall read_file_word_by_word5.cpp
// Προκειμένου το πρόγραμμα να διαβάζει ως είσοδο τα περιεχόμενα του αρχείου 1984_small.txt
// και να εκτελεστεί στη συνέχεια με: 
// $ a.exe < 1984_small.txt για windows
// $ ./a.out < 1984_small.txt για linux, macos

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ανάγνωση δεδομένων και εισαγωγή σε vector
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
