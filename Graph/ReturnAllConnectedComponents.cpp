#include <iostream>
#include <vector>
using namespace std;

void DFSForSingleComponent(int **edges, int n, int startingVertex, bool *visited, vector<int> *singleComponent)
{
    // cout << startingVertex << " ";
    singleComponent->push_back(startingVertex);
    visited[startingVertex] = true;

    for (int i = 0; i < n; i++)
    {
        if (edges[startingVertex][i] == 1 && visited[i] == false)
        {
            DFSForSingleComponent(edges, n, i, visited, singleComponent);
        }
    }
}

vector<vector<int> *> *DFS(int **graph, int numberOfNodes)
{
    vector<vector<int> *> *connectedComponents = new vector<vector<int> *>();

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
            vector<int> *singleComponent = new vector<int>();
            DFSForSingleComponent(graph, numberOfNodes, i, visited, singleComponent);
            connectedComponents->push_back(singleComponent);
        }
    }

    delete[] visited;

    return connectedComponents;
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

    vector<vector<int> *> *connectedComponents = DFS(adjacencyMatrix, n);

    for (int i = 0; i < connectedComponents->size(); i++)
    {
        vector<int> *singleComponent = connectedComponents->at(i);
        for (int j = 0; j < singleComponent->size(); j++)
        {
            cout << singleComponent->at(j) << " ";
        }
        cout << endl;
    }
}