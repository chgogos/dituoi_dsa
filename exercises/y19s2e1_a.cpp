#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

struct word_occurences
{
    std::string word;
    int occurences;
    bool operator<(const word_occurences &other) const
    {
        return occurences < other.occurences;
    }
};

// μη αποδοτικό αλλά λειτουργεί ;)
std::string capitalize(std::string s)
{
    std::string ns;
    for (char c : s)
    {
        ns.push_back(toupper(c));
    }
    return ns;
}

int main()
{
    std::fstream fin;
    fin.open("1984.txt", std::ios::in);
    std::string word;
    std::map<std::string, int> dictionary;
    while (fin >> word)
    {
        // αν θέλαμε να διώξουμε τα κόματα και τις τελείες από το τέλος λέξεων
        // if (word.back() == ',' || word.back() == '.')
        //     word = word.substr(0, word.length() - 1);
        word = capitalize(word);
        if (dictionary.find(word) == dictionary.end())
        {
            dictionary[word] = 1;
        }
        else
        {
            dictionary[word]++;
        }
    }
    fin.close();

    std::vector<word_occurences> items;
    for (auto kv : dictionary)
    {
        word_occurences item;
        item.word = kv.first;
        item.occurences = kv.second;
        items.push_back(item);
    }

    std::sort(items.begin(), items.end());
    for (auto item : items)
    {
        std::cout << item.word << " --> " << item.occurences << std::endl;
    }
}
