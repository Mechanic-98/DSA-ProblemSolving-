#include <iostream>
using namespace std;

void isConnected(int **graph, int numberOfNodes, int startingVertex, bool *visited)
{
    visited[startingVertex] = true;

    for (int i = 0; i < numberOfNodes; i++)
    {
        if (graph[startingVertex][i] == 1 && visited[i] == false)
        {
            isConnected(graph, numberOfNodes, i, visited);
        }
    }
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

        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    // visited array
    bool *visited = new bool[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        visited[i] = false;
    }

    isConnected(graph, numberOfNodes, 0, visited);

    bool ans = true;
    for (int i = 0; i < numberOfNodes; i++)
    {
        if (visited[i] == false)
        {
            ans = false;
            break;
        }
    }

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}