/*
Given a sorted dictionary of an alien language having N words and k starting
alphabets of standard dictionary. Find the order of characters in the alien
language.
Note: Many orders may be possible for a particular test case,
thus you may return any valid order and output will be 1 if the order of string
returned by the function is correct else 0 denoting incorrect string returned.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution
{
private:
    vector<int> topoSort_BFS(vector<int> adj[], int n)
    {
        int indegreeList[n] = {0}; // initializing all the members of the array with 0.
        queue<int> pendingNodes;
        vector<int> topoSortList;

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
            topoSortList.push_back(frontNode);

            for (int adjNode : adj[frontNode])
            {
                indegreeList[adjNode]--;
                if (indegreeList[adjNode] == 0)
                    pendingNodes.push(adjNode);
            }
        }

        return topoSortList;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adjList[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adjList[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort_BFS(adjList, K);
        string ans = "";
        for (auto node : topo)
        {
            ans = ans + char(node + 'a');
        }

        return ans;
    }
};