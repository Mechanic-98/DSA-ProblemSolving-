#include <iostream>
using namespace std;

bool isSafePosition(int **board, int row, int col, int n)
{
    // column check
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // upper left diagonal check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // upper right diagonal check
    for (int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    /* we are not checking for lower right diagonal, lower left diagonal & row
    because we  are filling borad from the upper right corner.
    */

    return true;
}

void placeNQueens(int **board, int &n, int curRow)
{
    if (curRow == n)
    {
        // we have reached some solution, print matrix and return.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    // Place at all possible positions and move to smaller problem
    for (int col = 0; col < n; col++)
    {
        if (isSafePosition(board, curRow, col, n))
        {
            board[curRow][col] = 1;

            /*
            Here because this is a hypothesis, all the work for smaller problem
            is supposed to be done, after this we have to reset the current position
            and check solution for next position.
            */
            placeNQueens(board, n, curRow + 1);

            // backtracking
            board[curRow][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int **board = new int *[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    placeNQueens(board, n, 0);
}