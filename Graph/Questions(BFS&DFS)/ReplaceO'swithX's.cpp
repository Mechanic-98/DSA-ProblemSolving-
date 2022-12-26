#include <iostream>
#include <vector>
using namespace std;

/*
Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’
at locations just below, just above, just left and just right of it.

{{'X', 'X', 'X', 'X'},      X X X X
{'X', 'O', 'X', 'X'},       X X X X
{'X', 'O', 'O', 'X'},   =>  X X X X
{'X', 'O', 'X', 'X'},       X X X X
{'X', 'X', 'O', 'O'}} .     X X O O


STEPS: Find boundary Os and traverse all connected nodes to boundary Os
       and mark them as visited. Convert all other Os to Xs

*/

void fillHelperDFS(int row, int col, vector<vector<int>> &visited, vector<vector<char>> mat, int dx[], int dy[], int n, int m)
{
    visited[row][col] = 1;
    // check for left, right, up and down

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            !visited[newRow][newCol] && mat[newRow][newCol] == 'O')
        {
            fillHelperDFS(newRow, newCol, visited, mat, dx, dy, n, m);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int dx[] = {0, 0, -1, 1}; // change in x while taking 4 moves
    int dy[] = {1, -1, 0, 0}; // change in y while taking 4 moves

    // check boundary nodes
    for (int j = 0; j < m; j++)
    {
        // first row
        if (!visited[0][j] && mat[0][j] == 'O')
        {
            fillHelperDFS(0, j, visited, mat, dx, dy, n, m);
        }

        // last row
        if (!visited[n - 1][j] && mat[n - 1][j] == 'O')
        {
            fillHelperDFS(n - 1, j, visited, mat, dx, dy, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        // first col
        if (!visited[i][0] && mat[i][0] == 'O')
        {
            fillHelperDFS(i, 0, visited, mat, dx, dy, n, m);
        }

        // last col
        if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
        {
            fillHelperDFS(i, m - 1, visited, mat, dx, dy, n, m);
        }
    }

    // changing mat
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}