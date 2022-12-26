#include <vector>
#include <queue>

using namespace std;

class Solution
{
    void dfs(vector<int> edges, int node, vector<bool> &visited, int &count)
    {
        visited[node] = true;
        count++;

        int adjNode = edges[node];
        if (adjNode != -1 && !visited[adjNode])
        {
            dfs(edges, adjNode, visited, count);
        }
    }

public:
    int longestCycle(vector<int> &edges)
    {

        // remove all nodes which are not part of cycles
        // kahn's algo, performing topological sort

        int n = edges.size();
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            int destinationNode = edges[i];
            if (destinationNode != -1)
            {
                indegree[destinationNode]++;
            }
        }

        queue<int> pendingNodes;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                pendingNodes.push(i);
            }
        }

        while (!pendingNodes.empty())
        {
            int frontNode = pendingNodes.front();
            pendingNodes.pop();

            int adjNode = edges[frontNode];
            if (adjNode != -1)
            {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0)
                    pendingNodes.push(adjNode);
            }
        }

        // now we have virtually removed nodes which were not the part of cycle,
        // as reflected in indegree array, not in edges(as it was input data)

        // vector<bool> visited(n, false);
        // int maxi = INT_MIN;

        // /*
        // run dfs for every node having indegree > 0,
        // find length of cycle and update maxi
        // */

        // for (int i = 0; i < n; i++)
        // {
        //     int count = 0;
        //     if (indegree[i] > 0 && !visited[i])
        //     {
        //         dfs(edges, i, visited, count);
        //     }

        //     maxi = max(maxi, count);
        // }

        // // if there are no cycle in graph, return -1
        // if (maxi == 0)
        //     return -1;

        // return maxi;

        // for DFS -> memory limit exceeded

        // BFS to check
        int ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] > 0 && !visited[i])
            {
                int count = 0;
                int currentNode = i;

                // till we hit that node again
                while (!visited[currentNode])
                {
                    count++;
                    visited[currentNode] = true;
                    currentNode = edges[currentNode];
                }

                ans = max(ans, count);
            }
        }

        if (ans == 0)
            return -1;
        return ans;
    }
};