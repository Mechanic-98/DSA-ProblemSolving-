
#define MOD 1e9 + 7

// Recursion

int numRollsToTarget(int numberOfDices, int numberOfFaces, int target)
{

    if (numberOfDices == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (target <= 0)
        return 0;

    int count = 0;
    for (int i = 1; i <= numberOfFaces; i++)
    {
        count += numRollsToTarget(numberOfDices - 1, numberOfFaces, target - i);
    }

    return count % MOD;
}

// Memoization

int helper(int dices, int faces, int target, vector<vector<int>> &dp)
{

    if (dices == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    }

    if (target <= 0)
        return 0;

    if (dp[dices][target] != -1)
    {
        return dp[dices][target];
    }

    int count = 0;

    for (int i = 1; i <= faces; i++)
    {
        if (i <= target)
        {
            count += helper(dices - 1, faces, target - i, dp);
            count = count % mod;
        }
    }
    dp[dices][target] = count;
    return dp[dices][target];
}

int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return helper(n, k, target, dp);
}

// DP
