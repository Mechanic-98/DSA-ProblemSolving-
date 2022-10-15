#include <iostream>
using namespace std;

bool hasPath(int **graph, int n, bool *visited, int sv, int ev)
{
    if (graph[sv][ev] == 1)
        return true;
    visited[sv] = true;

    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false && graph[sv][i] == 1)
            ans = hasPath(graph, n, visited, i, ev);

        if (ans)
            return ans;
    }

    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **adjacencyMatrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        adjacencyMatrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int first, second;
        cin >> first >> second;
        adjacencyMatrix[first][second] = 1;
        adjacencyMatrix[second][first] = 1;
    }

    // We can use both an array or an unordered_map (map will be faster)
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int sv, ev;
    cin >> sv >> ev;

    if (hasPath(adjacencyMatrix, n, visited, sv, ev))
        cout << "true";
    else
        cout << "false";
}