#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> *getReversePath(int **graph, int numberOfNodes, int v1, int v2)
{
    queue<int> pendingNodes;
    bool *visited = new bool[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
        visited[i] = false;

    pendingNodes.push(v1);
    visited[v1] = true;

    vector<int> parent(numberOfNodes, -1);

    bool pathFound = false;

    while (!pendingNodes.empty() && !pathFound)
    {
        int frontNode = pendingNodes.front();
        pendingNodes.pop();

        for (int i = 0; i < numberOfNodes; i++)
        {
            if (graph[frontNode][i] == 1 && !visited[i])
            {
                pendingNodes.push(i);
                visited[i] = true;
                parent[i] = frontNode;
                if (i == v2)
                {
                    pathFound = true;
                    break;
                }
            }
        }
    }

    delete[] visited;

    if (!pathFound)
        return NULL;

    vector<int> *path = new vector<int>();
    int current = v2;
    path->push_back(v2);

    while (current != v1)
    {
        current = parent[current];
        path->push_back(current);
    }

    return path;
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

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> *path = getReversePath(adjacencyMatrix, numberOfNodes, v1, v2);

    if (path != NULL)
    {
        for (int i = 0; i < path->size(); i++)
            cout << path->at(i) << " ";
        delete path;
    }

    for (int i = 0; i < numberOfNodes; i++)
        delete[] adjacencyMatrix[i];
    delete[] adjacencyMatrix;
}