// https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsHelper(int m, int n, int currRow, int currCol)
    {
        if (currRow >= m || currCol >= n)
            return 0;
        if (currRow == m - 1 &&currCol = n - 1)
            return 1;

        int fromRight = uniquePathsHelper(m, n, currRow, currCol + 1);
        int fromDown = uniquePathsHelper(m, n, currRow + 1, currCol);

        return fromRight + fromDown;
    }

    int uniquePaths(int m, int n)
    {
        int ans = uniquePathsHelper(m, n, 0, 0);
    }
};

// DP

class Solution
{
public:
    int uniquePathsHelper(int m, int n, int currRow, int currCol, vector<vector<int>> &dp)
    {
        if (currRow >= m || currCol >= n)
            return 0;
        if (currRow == m - 1 && currCol == n - 1)
            return 1;

        if (dp[currRow][currCol] != -1)
            return dp[currRow][currCol];

        int fromRight = uniquePathsHelper(m, n, currRow, currCol + 1, dp);
        int fromDown = uniquePathsHelper(m, n, currRow + 1, currCol, dp);

        dp[currRow][currCol] = fromRight + fromDown;

        return fromRight + fromDown;
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = uniquePathsHelper(m, n, 0, 0, dp);
        return ans;
    }
};