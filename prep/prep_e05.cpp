// Quiz MSTEAMS 9/6/2020

#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<string, int> dict;
    dict["ABC"] = 9;
    dict["DEF"] = 5;
    dict["GHI"] = 8;

    int t = 0;
    for (auto &k : {"ABC", "DEF", "GHI", "JKL", "MNO"})
    {
        if (dict.find(k) == dict.end())
            t += 10;
        else
            t += dict[k];
    }
    cout << t;
}

/*
42
*/