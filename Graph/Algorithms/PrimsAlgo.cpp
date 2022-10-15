#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int findMinVertex(int *incomingEdgeWeight, bool *visited, int numberOfNodes)
{
    int minVertex = -1;
    // Initialized to - 1 means there is no vertex till now
    for (int i = 0; i < numberOfNodes; i++)
    {
        // Conditions : the vertex must be unvisited and either minVertex value is -1
        // or if minVertex has some vertex to it, then weight of currentvertex
        // should be less than the weight of the minVertex.
        if (!visited[i] && (minVertex == -1 || incomingEdgeWeight[i] < incomingEdgeWeight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void primsAlgo(int **graph, int numberOfNodes) // T.C O(N*N)
{
    int *parent = new int[numberOfNodes];
    int *incomingEdgeWeight = new int[numberOfNodes];
    bool *visited = new bool[numberOfNodes];

    for (int i = 0; i < numberOfNodes; i++)
    {
        visited[i] = false;
        incomingEdgeWeight[i] = INT_MAX;
    }

    parent[0] = -1;
    incomingEdgeWeight[0] = 0;

    for (int i = 0; i < numberOfNodes - 1; i++) // O(N)
    {
        // Finding min Vertex
        int minVertex = findMinVertex(incomingEdgeWeight, visited, numberOfNodes); // O(N)
        visited[minVertex] = true;

        // Explore unvisited neighbouring vertex
        for (int j = 0; j < numberOfNodes; j++)
        {
            if (graph[minVertex][j] != 0 && !visited[j])
            { // edge exists and dest is not visited
                if (graph[minVertex][j] < incomingEdgeWeight[j])
                {
                    incomingEdgeWeight[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    // Printing MST
    for (int i = 1; i < numberOfNodes; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << incomingEdgeWeight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << incomingEdgeWeight[i] << endl;
        }
    }
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    // Graph
    int **graph = new int *[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        graph[i] = new int[numberOfNodes];
        for (int j = 0; j < numberOfNodes; j++)
        {
            graph[i][j] = 0;
        }
    }

    // filling edges & weights
    for (int i = 0; i < numberOfEdges; i++)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;

        graph[source][destination] = weight;
        graph[destination][source] = weight;
    }

    // We can improve this using priority queue and adjacency list
    primsAlgo(graph, numberOfNodes);
}