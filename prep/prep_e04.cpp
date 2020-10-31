// Quiz MSTEAMS 9/6/2020

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    string fname;
    string lname;
};
bool cmp(student &a, student &b)
{
    // να συμπληρωθεί
    if (a.lname == b.lname)
        return a.fname < b.fname;
    return a.lname < b.lname;
}
int main()
{
    vector<student> vs = {{"Maria", "Anagnostou"},
                          {"Kostas", "Anagnostakis"},
                          {"Giannis ", "Anagnostakis"}};
    sort(vs.begin(), vs.end(), cmp);
    for (auto &s : vs)
    {
        cout << s.lname << " " << s.fname << endl;
    }
}

/*
Anagnostakis Giannis
Anagnostakis Kostas
Anagnostou Maria
*/