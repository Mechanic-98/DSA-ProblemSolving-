#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int vertex, int *parent)
{
    if (vertex == parent[vertex])
        return vertex;

    return findParent(parent[vertex], parent);
}

void kruskals(Edge *input, int e, int n)
{
    sort(input, input + e, compare);

    Edge *output = new Edge[n - 1];
    int *parent = new int[n];

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int i = 0, count = 0;

    while (count != n - 1)
    {
        Edge currentEdge = input[i];

        int srcParent = findParent(currentEdge.src, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (srcParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[destParent] = srcParent;
        }
        i++;
    }

    // PrintingMST
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].src < output[i].dest)
        {
            cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
        }
    }
}

int main()
{
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    Edge *inputGraph = new Edge[numberOfEdges];

    for (int i = 0; i < numberOfEdges; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;

        inputGraph[i].src = src;
        inputGraph[i].dest = dest;
        inputGraph[i].weight = weight;
    }

    kruskals(inputGraph, numberOfEdges, numberOfNodes);
}