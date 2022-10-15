#include <iostream>
#include <string>
using namespace std;

int findWinnerRec(int n, int x, int y)
{
    if (n == 1 || n == x || n == y)
        return 1;

    int case1 = findWinnerRec(n - 1, x, y) ^ 1;
    int case2 = INT_MIN, case3 = INT_MIN;
    if (n > x)
        case2 = findWinnerRec(n - x, x, y) ^ 1;
    if (n > y)
        case3 = findWinnerRec(n - y, x, y) ^ 1;

    return max(case1, max(case2, case3));
}

// Memoization

int findWinnerMEM(int n, int x, int y, int *dp)
{
    if (n == 1 || n == x || n == y)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int case1 = findWinnerMEM(n - 1, x, y, dp) ^ 1;
    int case2 = INT_MIN, case3 = INT_MIN;
    if (n > x)
        case2 = findWinnerMEM(n - x, x, y, dp) ^ 1;
    if (n > y)
        case3 = findWinnerMEM(n - y, x, y, dp) ^ 1;

    dp[n] = max(case1, max(case2, case3));

    return dp[n];
}

// DP

int findWinnerDP(int n, int x, int y)
{
    int *dp = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == x || i == y)
        {
            dp[i] = 1;
            continue;
        }
        int case1 = dp[i - 1] ^ 1;
        int case2 = INT_MIN, case3 = INT_MIN;
        if (i > x)
            case2 = dp[i - x] ^ 1;
        if (i > y)
            case3 = dp[i - y] ^ 1;

        dp[i] = max(case1, max(case2, case3));
    }

    return dp[n];
}

string findWinner(int n, int x, int y)
{
    if (n == 1 || n == x || n == y)
        return "Beerus";

    // int result = findWinnerRec(n, x, y);

    // int*dp = new int[n+1];
    // for(int i=0; i<=n; i++) dp[i] = -1;
    // int result = findWinnerMEM(n,x,y,dp);

    int result = findWinnerDP(n, x, y);

    if (result)
        return "Beerus";

    return "Whis";
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}