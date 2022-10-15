#include <vector>
#include <cmath>

// Recursion TC: (2^N) S.C: O(N)
int solve(vector<int> &cost, int idx)
{
    if (idx == 0)
        return cost[0];
    if (idx == 1)
        return cost[1];

    // handling stair climb: 1 or 2
    int ans = cost[idx] + min(solve(cost, idx - 1), solve(cost, idx - 2));

    return ans;
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    // handling starting index: 0 or 1
    int ans = min(solve(cost, n - 1), solve(cost, n - 2));
    return ans;
}

// Memoization  T.C: O(N)  S.C: O(N) + O(N)

int solve(vector<int> &cost, int idx, vector<int> &dp)
{
    // base case
    if (idx == 0)
        return cost[0];
    if (idx == 1)
        return cost[1];

    if (dp[idx] != -1)
        return dp[idx];

    // handling stair climb: 1 or 2
    int ans = cost[idx] + min(solve(cost, idx - 1, dp), solve(cost, idx - 2, dp));
    dp[idx] = ans;

    return ans;
}

int minCostClimbingStairsMem(vector<int> &cost)
{

    int n = cost.size();
    vector<int> dp(n + 1, -1);

    // handling starting index: 0 or 1
    int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return ans;
}

// DP  T.C: O(N)  S.C: O(N) further optimised in this case-> O(1)

int solveDP(vector<int> &cost, int idx)
{
    vector<int> dp(idx + 1);
    // base case
    dp[0] = cost[0];
    dp[1] = cost[1];

    // handling stair climb: 1 or 2
    for (int i = 2; i < idx; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[idx - 1], dp[idx - 2]);
}

int solveDPSpaceOptimised(vector<int> &cost, int idx)
{
    // base case
    int prev2 = cost[0];
    int prev1 = cost[1];

    // handling stair climb: 1 or 2
    for (int i = 2; i < idx; i++)
    {
        int cur = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = cur;
    }

    return min(prev1, prev2);
}

int minCostClimbingStairs(vector<int> &cost)
{

    int n = cost.size();
    return solveDP(cost, n);
}