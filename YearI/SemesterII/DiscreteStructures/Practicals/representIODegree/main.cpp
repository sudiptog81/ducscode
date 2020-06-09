/**
 * WAP to accept a directed graph and calculate the in-degree
 * and out-degree of each vertex
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cmath>
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
        cout << "Enter the number of edges incoming to vertex " << i + 1 << ": ";
        cin >> e;
        // Iterate over the number of edges incoming to ith vertex
        for (int j = 0, f; j < e; j++)
        {
            cout << "Enter vertex from which the incoming edge to vertex " << i + 1 << " is emerging from: ";
            cin >> f;
            // Set -1 in correct position
            matrix[i][f - 1] = -1;
        }
        cout << "Enter the number of edges outgoing from vertex " << i + 1 << ": ";
        cin >> e;
        // Iterate over the number of edges outgoing from ith vertex
        for (int j = 0, f; j < e; j++)
        {
            cout << "Enter vertex from which the outgoing edge from vertex " << i + 1 << " is ending at: ";
            cin >> f;
            // Set 1 in correct position
            matrix[i][f - 1] = 1;
        }
    }
    // Calculate degrees for each vertex
    for (int i = 0; i < v; i++)
    {
        int inDegree = 0, outDegree = 0;
        for (int j = 0; j < v; j++)
        {
            if (matrix[i][j] == -1)
                inDegree += matrix[i][j];
            if (matrix[i][j] == 1)
                outDegree += matrix[i][j];
        }
        // Output the outdegrees and indegrees
        cout << "\nOutdegree of vertex " << i + 1 << ": " << outDegree
             << "\tIndegree of vertex " << i + 1 << ": " << abs(inDegree)
             << endl;
    }
    return 0;
}