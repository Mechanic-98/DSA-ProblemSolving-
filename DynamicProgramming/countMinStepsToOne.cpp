#include <iostream>
using namespace std;

// Recursion: T.C.  O(3^N)
int countMinStepsToOne(int n)
{
    if (n <= 1)
        return 0;

    int case1 = countMinStepsToOne(n - 1);
    int case2 = INT_MAX, case3 = INT_MAX;

    if (n % 2 == 0)
        case2 = countMinStepsToOne(n / 2);
    if (n % 3 == 0)
        case3 = countMinStepsToOne(n / 3);

    return min(case1, min(case2, case3)) + 1;
}

// Memoization

int countMinStepsToOneMem(int n, int *dp)
{
    if (n <= 1)
        return 0;

    // Check in dp
    if (dp[n] != -1)
        return dp[n];

    // Recursive  calls
    int case1 = countMinStepsToOneMem(n - 1, dp);
    int case2 = INT_MAX, case3 = INT_MAX;

    if (n % 2 == 0)
        case2 = countMinStepsToOneMem(n / 2, dp);
    if (n % 3 == 0)
        case3 = countMinStepsToOneMem(n / 3, dp);

    dp[n] = min(case1, min(case2, case3)) + 1;
    return dp[n];
}

int countMinStepsToOne(int n)
{
    if (n <= 1)
        return 0;

    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    return countMinStepsToOneMem(n, dp);
}