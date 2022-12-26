#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// T.C: O(V + E)
void topologicalSortHelperDFS(int node, vector<int> &visited, vector<int> adj[], stack<int> &st)
{
    visited[node] = 1;

    for (auto adjNode : adj[node])
    {
        if (!visited[adjNode])
            topologicalSortHelperDFS(adjNode, visited, adj, st);
    }

    // when no dfs is to be made (while backtracking)
    st.push(node);
}

vector<int> topologicalSort(vector<int> adj[], int n)
{
    vector<int> visited(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topologicalSortHelperDFS(i, visited, adj, st);
        }
    }

    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}