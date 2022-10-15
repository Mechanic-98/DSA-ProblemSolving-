#include <iostream>
#include <vector>
using namespace std;

vector<int> getReversePath(int **graph, int numberOfNodes, int v1, int v2, int *visited, vector<int> &ans)
{
    if (v1 == v2)
    {
        ans.push_back(v2);
        return ans;
    }

    visited[v1] = 1;
    for (int i = 0; i < numberOfNodes; i++)
    {
        if (graph[v1][i] == 1 && visited[i] == 0)
        {
            getPath(graph, numberOfNodes, i, v2, visited, ans);
        }

        if (ans.size() != 0)
        {
            ans.push_back(v1);
            return ans;
        }
    }

    return ans;
}

vector<int> getPath(int **graph, int numberOfNodes, int v1, int v2, int *visited, vector<int> &ans)
{
    if (v1 == v2)
    {
        ans.push_back(v2);
        return ans;
    }

    visited[v1] = 1;
    ans.push_back(v1);

    for (int i = 0; i < numberOfNodes; i++)
    {
        if (graph[v1][i] == 1 && visited[i] == 0)
        {
            return getPath(graph, numberOfNodes, i, v2, visited, ans);
        }
    }

    // backtracking
    ans.pop_back();

    return ans;
}

int main()
{
    // Write your code here
    int numberOfNodes, numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;

    // create graph (adjacency matrix)
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

    int v1, v2;
    cin >> v1 >> v2;

    int *visited = new int[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++)
    {
        visited[i] = 0;
    }

    vector<int> ans = {};

    ans = getReversePath(graph, numberOfNodes, v1, v2, visited, ans);

    if (ans.size())
    {
        for (auto ele : ans)
        {
            cout << ele << " ";
        }
    }
}