#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pixel
{
    unsigned short red, green, blue;
};

double luminance(const pixel &p)
{
    return 0.2126 * p.red + 0.7152 * p.green + 0.0722 * p.blue;
}

bool operator<(const pixel &p1, const pixel &p2)
{
    return luminance(p1) < luminance(p2);
}

int main()
{
    vector<pixel> v = {{123, 45, 90}, {15, 245, 178}, {5, 5, 5}, {200, 200, 200}};
    sort(v.begin(), v.end());
    for (pixel p : v)
        cout << p.red << " " << p.green << " " << p.blue << endl;
}