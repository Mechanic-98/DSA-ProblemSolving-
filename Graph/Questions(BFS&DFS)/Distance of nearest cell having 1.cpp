#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number
and column number of the current cell, and i2, j2 are the row number and column number
of the nearest cell having value 1.


1 0 0 1 .     0 1 1 0
0 0 1 0 . =>  1 1 0 1
1 1 0 0 .     0 0 1 2


use BFS as we are considering distance,

we'll mark 1 as starting vertex and move level wise
*/

// TC: O(nxm) SC: O(nxm)
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> pendingNodes; // {{row, col}, distance}

    // n x m
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                pendingNodes.push({{i, j}, 0});
                visited[i][j] = true;
            }
            else
            {
                visited[i][j] = false;
            }
        }
    }
    int dx[] = {0, 0, -1, 1}; // change in x while taking 4 moves
    int dy[] = {1, -1, 0, 0}; // change in y while taking 4 moves

    // 4 x n x m
    while (!pendingNodes.empty())
    {
        int row = pendingNodes.front().first.first;
        int col = pendingNodes.front().first.second;
        int numberOfSteps = pendingNodes.front().second;
        pendingNodes.pop();

        distance[row][col] = numberOfSteps;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol])
            {
                visited[newRow][newCol] = true;
                pendingNodes.push({{newRow, newCol}, numberOfSteps + 1});
            }
        }
    }

    return distance;
}

int main()
{
    vector<vector<int>> grid;
    nearest(grid);
}