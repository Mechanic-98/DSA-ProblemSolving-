#include <iostream>
using namespace std;

int get3Cycles(int **graph, int numberOfNodes)
{
    int cycleCount = 0;

    for (int i = 0; i < numberOfNodes - 2; i++)
    {
        for (int j = i + 1; j < numberOfNodes - 1; j++)
        {
            for (int k = j + 1; k < numberOfNodes; k++)
            {
                if (graph[i][j] == 1 && graph[j][k] == 1 && graph[k][i] == 1)
                    cycleCount++;
            }
        }
    }

    return cycleCount;
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
        int first, second;
        cin >> first >> second;

        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    // We're avoiding visited array especially for this question

    cout << get3Cycles(graph, numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++)
    {
        delete[] graph[i];
    }

    delete[] graph;
}
