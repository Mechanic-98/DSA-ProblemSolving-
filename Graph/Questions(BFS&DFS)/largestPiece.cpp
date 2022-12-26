#include <iostream>
#include <vector>
using namespace std;

/*
same problem diff name:
    1. Number of Distinct islands
*/

/*

1 1 0 1       1 1
0 1 1 0   =>    1 1   ans = 6
1 1 0 0       1 1

*/

int DFS(vector<vector<int>> &cake, vector<vector<bool>> &visited, int x, int y, int n)
{
    if (visited[x][y])
        return 0;

    visited[x][y] = true;
    int count = 1;

    int dx[] = {0, 0, -1, 1}; // change in x while taking 4 moves
    int dy[] = {1, -1, 0, 0}; // change in y while taking 4 moves

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < n && cake[newX][newY] == 1)
        {
            count += DFS(cake, visited, newX, newY, n);
        }
    }

    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    int biggestPieceSize = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                biggestPieceSize = max(biggestPieceSize, DFS(cake, visited, i, j, n));
            }
        }
    }

    return biggestPieceSize;
}