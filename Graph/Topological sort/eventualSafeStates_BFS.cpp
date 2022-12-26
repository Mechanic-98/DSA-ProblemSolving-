/*
https://leetcode.com/problems/find-eventual-safe-states/
*/

/*
strategy: reverse graph, trace back from terminal node to whereever it is possible,
          it will include all those nodes who don't form a cycle at all.

why some nodes are not safe nodes?
because they have some path which leads to cycle, that is the explaination
for the solution.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> graphRev[n];
        vector<int> indegree(n, 0);
        queue<int> pendingNodes;
        vector<int> safeNodes;

        for (int i = 0; i < n; i++)
        {
            for (auto adjNode : graph[i])
            {

                graphRev[adjNode].push_back(i);
                indegree[i]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                pendingNodes.push(i);
        }

        while (!pendingNodes.empty())
        {
            int frontNode = pendingNodes.front();
            pendingNodes.pop();
            safeNodes.push_back(frontNode);

            for (int adjNode : graphRev[frontNode])
            {

                indegree[adjNode]--;
                if (indegree[adjNode] == 0)
                    pendingNodes.push(adjNode);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};