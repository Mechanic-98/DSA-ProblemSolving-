#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool *visited, int *distanceFromSource, int numberOfNodes)
{
    int minVertex = -1;
    // Initialized to - 1 means there is no vertex till now
    for (int i = 0; i < numberOfNodes; i++)
    {
        // Conditions : the vertex must be unvisited and either minVertex value is -1
        // or if minVertex has some vertex to it, then distance of currentvertex
        // should be less than the distance of the minVertex.
        if (!visited[i] && (minVertex == -1 || distanceFromSource[i] < distanceFromSource[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstraAlgo(int **graph, int numberOfNodes)
{
    int *distanceFromSource = new int[numberOfNodes];
    distanceFromSource[0] = 0;
    for (int i = 1; i < numberOfNodes; i++)
        distanceFromSource[i] = INT_MAX;

    bool *visited = new bool[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
        visited[i] = false;

    for (int i = 0; i < numberOfNodes; i++)
    {
        int minVertex = findMinVertex(visited, distanceFromSource, numberOfNodes);
        visited[minVertex] = true;

        // Exploring neighboringNodes
        for (int j = 0; j < numberOfNodes; j++)
        {
            if (graph[minVertex][j] != 0 && !visited[j])
            {
                int distance = distanceFromSource[minVertex] + graph[minVertex][j];
                if (distance < distanceFromSource[j])
                {
                    distanceFromSource[j] = distance;
                }
            }
        }
    }

    // Printing Nodes with distances
    for (int i = 0; i < numberOfNodes; i++)
    {
        cout << i << " " << distanceFromSource[i] << endl;
    }
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

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
        int firstNode, secondNode, weight;
        cin >> firstNode >> secondNode >> weight;
        graph[firstNode][secondNode] = weight;
        graph[secondNode][firstNode] = weight;
    }

    dijkstraAlgo(graph, numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++)
    {
        delete[] graph[i];
    }

    delete[] graph;
}