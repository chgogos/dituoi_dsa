#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;
#define N 248

int main()
{
    string countries[N];
    string abbr[N];
    int pop[N][57];
    string line, word;
    fstream fin;

    // για απλότητα έχουν αφαιρεθεί οι χώρες με ονόματα σε "" καθώς και οι χώρες χωρίς δεδομένα στο πλέον πρόσφατο έτος
    fin.open("population-figures-easy.csv", ios::in);
    getline(fin, line);
    int i = 0;
    while (getline(fin, line))
    {
        stringstream ss(line);
        int k = 0;
        while (getline(ss, word, ','))
        {
            if (k == 0)
                countries[i] = word;
            else if (k == 1)
                abbr[i] = word;
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

    for (int i = 0; i < N; i++)
    {
        cout << countries[i] << " (" << abbr[i] << ") ";
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