#include <bits/stdc++.h>
using namespace std;

int maxWaysClimbingStairsPermutationsRec(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    int case1 = maxWaysClimbingStairsPermutationsRec(n - 1);
    int case2 = maxWaysClimbingStairsPermutationsRec(n - 2);
    int case3 = maxWaysClimbingStairsPermutationsRec(n - 3);

    return case1 + case2 + case3;
}

// Memoization
int maxWaysClimbingStairsPermutationsMem(int n, int *dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int case1 = maxWaysClimbingStairsPermutationsRec(n - 1);
    int case2 = maxWaysClimbingStairsPermutationsRec(n - 2),
        int case3 = maxWaysClimbingStairsPermutationsRec(n - 3);

    dp[n] = case1 + case2 + case3;
    return dp[n];
}

// DP
int maxWaysClimbingStairsPermutationsDP(int n)
{
    long *ans = new long[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; i++)
        ans[i] = (ans[i - 1] + ans[i - 2] + ans[i - 3]) % mod;
    return ans[n];
}

int main()
{

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int numberOfSteps;
        cin >> numberOfSteps;

        // cout<<maxWaysClimbingStairsPermutationsRec(numberOfSteps)<<endl;

        // int *dp = new int[numberOfSteps + 1];
        // for (int i = 0; i < numberOfSteps; i++)
        //     dp[i] = -1;

        // cout << maxWaysClimbingStairsPermutationsMem(numberOfSteps, dp) << endl;

        cout << maxWaysClimbingStairsPermutationsDP(numberOfSteps) << endl;
    }
    return 0;
}