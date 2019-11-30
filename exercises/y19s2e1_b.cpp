#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    typedef std::pair<std::string, int> string_int;
    std::fstream fin;
    fin.open("1984.txt", std::ios::in);
    std::string word;
    std::map<std::string, int> dictionary;
    while (fin >> word)
    {
        std::transform(word.begin(), word.end(), word.begin(), toupper);
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

    std::vector<string_int> items;
    for (auto &kv : dictionary)
    {
        items.push_back(kv);
    }

    std::sort(items.begin(), items.end(),
              [](string_int &item1, string_int &item2) { return item1.second < item2.second; });

    for (auto item : items)
    {
        std::cout << item.first << " --> " << item.second << std::endl;
    }
}