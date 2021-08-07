/**
 * Simulate and implement Dijkstra algorithm for 
 * shortest path routing.
 * 
 * Written by Sudipto Ghosh for the University of Delhi
 */

#include <cstdio>
#include <climits>
#include <iomanip>
#include <iostream>
#define MAX_NODES 10

using namespace std;

class Graph
{
public:
  int edges;
  int vertices;
  int path[MAX_NODES];
  int distances[MAX_NODES];
  int adjMatrix[MAX_NODES][MAX_NODES];

  void input(int v, int e)
  {
    edges = e;
    vertices = v;

    // initialize the adjacency matrix
    for (int i = 0; i < v; i++)
      for (int j = 0; j < v; j++)
        adjMatrix[i][j] = 0;

    int src, dest, weight;

    // populate the adjacency matrix
    for (int i = 0; i < edges; i++)
    {
      cout << "\nEDGE " << (i + 1)
           << "\n======\n";
      cout << "Enter Source: ";
      cin >> src;
      cout << "Enter Destination: ";
      cin >> dest;
      cout << "Enter Weight: ";
      cin >> weight;
      adjMatrix[src - 1][dest - 1] = weight;
      adjMatrix[dest - 1][src - 1] = weight;
    }
  }

  void display()
  {
    for (int i = 0; i < vertices; i++)
    {
      for (int j = 0; j < vertices; j++)
        cout << setw(5) << adjMatrix[i][j] << " ";
      cout << endl;
    }
  }

  void dijkstra(int src)
  {
    bool visited[MAX_NODES];

    for (int i = 0; i < vertices; i++)
    {
      visited[i] = false;     // mark node as not processed
      distances[i] = INT_MAX; // set distance from src as infinity
    }

    // mark the src node
    path[src] = -1;
    distances[src] = 0;

    // iterate over all vertices
    for (int i = 0; i < vertices - 1; i++)
    {
      // find the nearest unprocessed node
      int u = minDistance(visited);
      // mark node as processed
      visited[u] = true;
      // iterate over all nodes
      for (int v = 0; v < vertices; v++)
        // update distance for unprocessed node if there
        // exists an edge(u,v) and new distance is lesser
        // also add the node to the shortest path
        if (visited[v] == false &&
            adjMatrix[u][v] &&
            distances[u] != INT_MAX &&
            distances[u] + adjMatrix[u][v] < distances[v])
        {
          path[v] = u;
          distances[v] = distances[u] + adjMatrix[u][v];
        }
    }

    // print distances and shortest paths
    cout << "\nDest Node \t Distance \t Shortest Path";
    cout << "\n========= \t ======== \t =============";
    for (int i = 0; i < vertices; i++)
    {
      cout << endl
           << (i + 1)
           << " \t\t " << distances[i]
           << " \t\t " << (src + 1);
      printShortestPath(i);
    }
  }

  int minDistance(bool *visited)
  {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
      if (visited[v] == false &&
          distances[v] <= min)
      {
        min = distances[v];
        min_index = v;
      }
    return min_index;
  }

  void printShortestPath(int node)
  {
    if (path[node] == -1)
      return;
    printShortestPath(path[node]);
    cout << " -> " << (node + 1);
  }
};

int main()
{
  int v, e;
  Graph graph;

  cout << "Enter No. of Nodes: ";
  cin >> v;
  cout << "Enter No. of Edges: ";
  cin >> e;

  graph.input(v, e);

  cout << "\nGRAPH\n=====\n";
  graph.display();
  cout << endl;

  cout << "Enter Source Node: ";
  cin >> v;

  graph.dijkstra(v - 1);

  return 0;
}
