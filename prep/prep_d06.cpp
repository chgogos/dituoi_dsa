#include <iostream>
#include <vector>

using namespace std;

#define V 6

string vertices[V] = {"A", "B", "C", "D", "E", "F"};

int adj_matrix[V][V] = {
    {0, 2, 6, 0, 0, 0},
    {2, 0, 3, 1, 0, 0},
    {6, 3, 0, 4, 3, 0},
    {0, 1, 4, 0, 2, 10},
    {0, 0, 3, 2, 0, 5},
    {0, 0, 0, 10, 5, 0}};

vector<string> get_connected_vertices(string v)
{
    vector<string> connected_vertices;
    for (int i = 0; i < V; i++)
        if (vertices[i] == v)
            for (int j = 0; j < V; j++)
                if (adj_matrix[i][j] != 0)
                    connected_vertices.push_back(vertices[j]);
    return connected_vertices;
}

int main()
{
    for (int i = 0; i < V; i++)
    {
        vector<string> conn = get_connected_vertices(vertices[i]);
        cout << "\nVertex " << vertices[i] << " ";
        for (string v : conn)
        {
            cout << v;
        }
    }
}