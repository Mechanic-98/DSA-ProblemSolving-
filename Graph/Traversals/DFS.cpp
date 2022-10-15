#include <iostream>
using namespace std;

// Undirected graph
/*
This algo is designed for the case when vertices are numbered from 0 -> n-1
*/

void printDFSForSingleComponent(int **edges, int n, int startingVertex, bool *visited)
{
    cout << startingVertex << " ";
    visited[startingVertex] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[startingVertex][i] == 1 && visited[i] == false)
        {
            printDFSForSingleComponent(edges, n, i, visited);
        }
    }
}

void printDFS(int **graph, int numberOfNodes)
{
    // creating visited array
    bool *visited = new bool[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        visited[i] = false;
    }

    // for disconnected graphs component
    for (int i = 0; i < numberOfNodes; i++)
    {
        if (!visited[i])
        {
            printDFSForSingleComponent(graph, numberOfNodes, i, visited);
        }
    }

    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **adjacencyMatrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        adjacencyMatrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int first, second;
        cin >> first >> second;
        adjacencyMatrix[first][second] = 1;
        adjacencyMatrix[second][first] = 1;
    }

    printDFS(adjacencyMatrix, n);
}