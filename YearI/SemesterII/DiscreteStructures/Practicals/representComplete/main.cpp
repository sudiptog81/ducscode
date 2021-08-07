/**
 * WAP to represent a graph using adjacency matrix and check
 * if a graph G is complete or not
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
using namespace std;
int main()
{
    // Accept the number of vertices in the graph
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    // Initialize the Adjacency Matrix with zeroes
    int matrix[v][v];
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            matrix[i][j] = 0;
    // Iterate over the number of vertices
    for (int i = 0, e; i < v; i++)
    {
        cout << "Enter the number of vertices adjacent to vertex " << i + 1 << ": ";
        cin >> e;
        // Iterate over the number of verices adjacent to ith vertex
        for (int j = 0, f; j < e; j++)
        {
            cout << "Enter vertex that is adjacent to vertex " << i + 1 << ": ";
            cin >> f;
            // Set 1 in correct position
            matrix[i][f - 1] = 1;
        }
    }
    // Display the Adjacency Matrix
    cout << "\nADJACENCY MATRIX\n-----------------\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    // Calculate Row Sum for each Row in Adjacency Matrix
    int flag = 0;
    for (int i = 0; i < v; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < v; j++)
            rowSum += matrix[i][j];
        // Check condition for Complete Graph
        if (rowSum != (v - 1))
            flag = 1;
    }
    // Output the nature of the graph
    if (!flag)
        cout << "\nGraph is complete!\n";
    else
        cout << "\nGraph is not complete!\n";
    return 0;
}