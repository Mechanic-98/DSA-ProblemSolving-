#include <iostream>
using namespace std;

void DFS(int **graph, int numberOfNodes, int startingVertex, bool *visited)
{
    visited[startingVertex] = true;
    for (int i = 0; i < numberOfNodes; i++)
    {
        if (graph[startingVertex][i] == 1 && !visited[i])
        {
            DFS(graph, numberOfNodes, i, visited);
        }
    }
}

int getNumberOfComponents(int **graph, int numberOfNodes)
{
    // creating visited array
    bool *visited = new bool[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        visited[i] = false;
    }

    int count = 0;

    // using DFS traversal for single component
    for (int i = 0; i < numberOfNodes; i++)
    {
        if (!visited[i])
        {
            DFS(graph, numberOfNodes, i, visited);
            count++;
        }
    }

    return count;
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    // creating graph
    int **graph = new int *[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        graph[i] = new int[numberOfNodes];
        for (int j = 0; j < numberOfNodes; j++)
        {
            graph[i][j] = 0;
        }
    }

    // filling edges
    for (int i = 0; i < numberOfEdges; i++)
    {
        int first, second;
        cin >> first >> second;

        // undirected graph
        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    // using DFS traversal
    int countOfComponents = getNumberOfComponents(graph, numberOfNodes);

    cout << countOfComponents << endl;
}