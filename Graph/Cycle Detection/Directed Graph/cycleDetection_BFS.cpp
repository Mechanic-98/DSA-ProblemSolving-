/* KAHN'S ALGO */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// T.C: O(V + E)
bool topoSort_BFS(vector<int> adj[], int n)
{
    int indegreeList[n] = {0}; // initializing all the members of the array with 0.
    queue<int> pendingNodes;
    int count = 0;

    // filling indegreeList
    for (int i = 0; i < n; i++)
    {
        for (int adjNode : adj[i])
        {
            indegreeList[adjNode]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegreeList[i] == 0)
        {
            pendingNodes.push(i);
        }
    }

    while (!pendingNodes.empty())
    {
        int frontNode = pendingNodes.front();
        pendingNodes.pop();
        count++;

        for (int adjNode : adj[frontNode])
        {
            indegreeList[adjNode]--;
            if (indegreeList[adjNode] == 0)
                pendingNodes.push(adjNode);
        }
    }

    return !(count == n);
}