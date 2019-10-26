#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    string countries[263];
    string abbr[263];
    int pop[263][57];

    fstream fin;
    fin.open("population-figures-by-country-csv_csv.csv", ios::in);
    string line, word;
    getline(fin, line);
    int i = 0;
    while (getline(fin, line))
    {
        line.pop_back(); // αφαίρεση \r\n για την περίπτωση που δεν υπάρχουν δεδομένα στην τελευταία χρονιά
        stringstream ss(line);
        int k = 0;
        if (line[0] == '\"') // χειρισμός περίπτωσης που το όνομα είναι μέσα σε εισαγωγικά
        {
            getline(ss, word, '\"');
            getline(ss, word, '\"');
            countries[i] = word;
            getline(ss, word, ',');
            k = 1;
        }
        if (line.back() == ',')
            line.push_back('0');

        while (getline(ss, word, ','))
        {
            if (k == 0)
            {
                countries[i] = word;
            }
            else if (k == 1)
            {
                abbr[i] = word;
            }
            else
            {
                if (word == "")
                    pop[i][k - 2] = 0;
                else
                    pop[i][k - 2] = stol(word);
            }
            k++;
        }
        i++;
    }
    fin.close();

    for (int i = 0; i < 263; i++)
    {
        cout << countries[i];
        double max = 0.0;
        int pmax = -1;
        for (int j = 1; j < 57; j++)
        {
            if (pop[i][j - 1] == 0 || pop[i][j] == 0)
                continue;
            double perc = (pop[i][j] - pop[i][j - 1]) / (double)pop[i][j - 1];
            if (abs(perc) > abs(max))
            {
                max = abs(perc);
                pmax = j - 1;
            }
        }
        cout << setprecision(4);
        cout << " max percentage " << max * 100 << "% years: " << pmax + 1960 << " - " << pmax + 1961 << endl;
    }
}