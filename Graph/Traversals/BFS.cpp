#include <iostream>
#include <queue>
using namespace std;

void printBFSForSingleComponent(int **graph, int numberOfNodes, int startingVertex, bool *visited)
{

    // structure to track levels
    queue<int> pendingNodes;
    pendingNodes.push(startingVertex);
    visited[startingVertex] = true;

    while (!pendingNodes.empty())
    {
        int frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout << frontNode << " ";

        for (int i = 0; i < numberOfNodes; i++)
        {
            if (graph[frontNode][i] == 1 && !visited[i])
            {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
}

void printBFS(int **graph, int numberOfNodes)
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
            printBFSForSingleComponent(graph, numberOfNodes, i, visited);
        }
    }

    delete[] visited;
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    // creating structure to store graph info
    int **adjacencyMatrix = new int *[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        adjacencyMatrix[i] = new int[numberOfNodes];
        for (int j = 0; j < numberOfNodes; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // filling graph using user input
    for (int i = 0; i < numberOfEdges; i++)
    {
        int first, second;
        cin >> first >> second;
        adjacencyMatrix[first][second] = 1;
        adjacencyMatrix[second][first] = 1;
    }

    // printing using BFS traversal
    printBFS(adjacencyMatrix, numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++)
    {
        delete[] adjacencyMatrix[i];
    }

    delete[] adjacencyMatrix;
}