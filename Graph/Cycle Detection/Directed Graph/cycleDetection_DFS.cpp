#include <iostream>
#include <vector>
using namespace std;

// time complexity = V + E, space complexity = 2V

// can use a single array visited, hint: vis = 1, pathVisited = 2;

bool isCyclicForSingleComponentDFS(vector<int> adjList[], int n, int sv, bool *visited, bool *pathVisited)
{
    visited[sv] = true;
    pathVisited[sv] = true;

    for (auto adjNode : adjList[sv])
    {
        if (!visited[adjNode])
        {
            if (isCyclicForSingleComponentDFS(adjList, n, adjNode, visited, pathVisited))
                return true;
        }
        else if (pathVisited[adjNode])
            return true;
    }

    pathVisited[sv] = false;
    return false;
}

bool isCyclic(vector<int> adjList[], int n)
{
    bool *visited = new bool[n];
    bool *pathVisited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (isCyclicForSingleComponentDFS(adjList, n, i, visited, pathVisited))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
}