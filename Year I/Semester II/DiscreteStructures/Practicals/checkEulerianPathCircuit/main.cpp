#include <iostream>

using namespace std;

/**
 * Given an adjacency matrix of a graph, write a program
 * to check whether a given set of vertices {v1,v2,v3,...
 * ,vk} forms an Euler path / Euler circuit (for circuit
 * assume vk = v1)
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */
int main()
{
    // Get number of vertices
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize the Adjacency Matrix with zeroes
    int matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;

    // Accept the graph
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    // Check for Eulerian path / circuit
    int degree, order = 0;
    for (int i = 0; i < n; i++)
    {
        degree = 0;

        for (int j = 0; j < n; j++)
            degree += matrix[i][j];

        if (degree % 2 != 0)
            order++;
    }

    if (order == 0)
        cout << "Graph has an Eulerian Circuit!" << endl;
    else if (order == 2)
        cout << "Graph has an Eulerian Path!" << endl;
    else
        cout << "Graph is Not Eulerian!" << endl;

    return 0;
}