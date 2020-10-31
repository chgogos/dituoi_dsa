/*
Γράψτε κώδικα που να εμφανίζει τις κορυφές που έχουν μια μόνο 
εξερχόμενη ακμή
*/

#include <iostream>
#include <vector>

using namespace std;

#define V 7

string vertices[V] = {"A", "B", "C", "D", "E", "F", "G"};
int adj_matrix[V][V] = {{0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0}};

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
        if (conn.size() == 1)
            cout << "\nVertex " << vertices[i] << " ";
    }
}