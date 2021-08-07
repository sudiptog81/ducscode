/**
 * Given a graph G, write a Program to find the number of paths 
 * of length n between the source and destination entered by the 
 * user.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <iostream>
#define MAX_NODES 100
using namespace std;
/**
 * Returns the number of posible paths from
 * src to dest nodes of a graph having exactly
 * len edges
 */
int countPaths(
    int graph[][MAX_NODES], int n,
    int src, int dest, int len)
{
    // Declare Counter
    int count[n][n][len + 1];
    // Iterate over number of edges [0..len]
    for (int e = 0; e <= len; e++)
    {
        // Iterate over source nodes [0..n-1]
        for (int i = 0; i < n; i++)
        {
            // Iterate over destination nodes [0..n-1]
            for (int j = 0; j < n; j++)
            {
                // Initialize counter
                count[i][j][e] = 0;
                // Case 1:
                // Edges = 0 and Src Node == Dest Node
                if (e == 0 && i == j)
                    count[i][j][e] = 1;
                // Case 2:
                // Edges = 1 and Direct Path Exists
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;
                // Case 3:
                //   Dest is not directly connected to Src
                if (e > 1)
                    // Iterate over all neighbours of ith Node
                    for (int a = 0; a < n; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e - 1];
            }
        }
    }
    return count[src][dest][len];
}
int main()
{
    // Accept the number of vertices in the graph
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    // Accept the Adjacency Matrix of the graph
    int matrix[MAX_NODES][MAX_NODES];
    cout << "Enter the Adjacency Matrix: " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cin >> matrix[i][j];
    }
    // Determine the src and dest nodes
    int src, dest;
    cout << "Enter Source Node: ";
    cin >> src;
    cout << "Enter Destination Node: ";
    cin >> dest;
    // Determine the path length
    int len;
    cout << "Enter Path Length: ";
    cin >> len;
    // Print the number of paths possible
    cout << "Total Paths from Node "
         << src << " to Node " << dest
         << " having " << len << " edges: "
         << countPaths(
                matrix, v,
                src - 1, dest - 1,
                len);
    return 0;
}