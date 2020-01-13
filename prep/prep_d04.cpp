#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> players = {{"kostas", 0}, {"maria", 0}, {"nikos", 0}};
    for (int i = 0; i < 3; i++)
    {
        string name;
        int score;
        cout << "Enter name and score: ";
        cin >> name >> score;
        if (players.find(name) != players.end())
            players[name] += score;
    }

    for (auto &kv : players)
    {
        cout << "Player: " << kv.first << " score:" << kv.second << endl;
    }
}