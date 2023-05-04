// https://leetcode.com/problems/set-matrix-zeroes/

/*
Approach1 (Brute force): O( (N*M) * (N+M) )
-> setting all values to -1 other than 0, if 0 is found on traversal.
-> changing all -1 to 0.

Approach2 (Dummy row and Dummy col): O(N*M + N*M) O(N + M)
-> if arr[i][j] == 0 then put dummyRow[i] = 0 and dummyCol[j] = 0;
-> traverse and check for every arr[i][j] the value of dummyRow and dummyCol;
    if found zero in any of them, put arr[i][j] = 0;

Approach3 (make first row and first column as dummyRow adn dummyCol): O(N*M + N*M) O(1)
-> var colFlag = true why?
    dummy col's zero must impact col not dummy row
-> if arr[i][j] == 0 then put dummyRow[i] = 0 and dummyCol[j] = 0;
    if arr[i][0] == 0; i.e. if 0th col has zero then change colFlag = false;
    means entire 0th col will be zero
-> To have similar check for row, traverse from last arr[n-1][m-1];
    basically we'll change dummy row i.e. the first row of matrix after when
    it has served its purpose.
*/

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int columns = matrix[0].size(), rows = matrix.size();
    bool isDummyColZero = false;

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
            isDummyColZero = true;
        for (int j = 1; j < columns; j++)
        {
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = columns - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }

        if (isDummyColZero)
            matrix[i][0] = 0;
    }
}