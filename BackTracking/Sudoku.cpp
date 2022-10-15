#include <iostream>
#include <string>
using namespace std;

#define N 9

bool findingEmptyLocation(int grid[N][N], int &row, int &col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    // checking rows and columns
    for (int i = 0; i < N; i++)
    {
        // checking row
        if (grid[row][i] == num)
            return false;

        // checking col
        if (grid[i][col] == num)
            return false;
    }

    // checking smaller grid (3x3 box)
    // rowFactor = row - (row%3)  and colFactor = col - (col%3)

    int rowFactor = row - (row % 3), colFactor = col - (col % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + rowFactor][j + colFactor] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N])
{
    int row, col;
    if (findingEmptyLocation(grid, row, col) == false)
        return true;

    for (int i = 1; i < N; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;

            // if the rest of the sudoku is solved using 'i' ->fine, else backtrack.
            if (solveSudoku(grid))
                return true;

            // backtracking to reset the position to its initial val
            grid[row][col] = 0;

            // loop will go on to find another value
        }
    }

    // getting out of this loop means, no value exists for this empty location
    return false;
}

int main()
{
    int grid[N][N];

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }

    solveSudoku(grid);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}