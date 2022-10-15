#include <cmath>

// Recursion: T.C: O(2^n) S.C: O(N)
int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // write your code here
    if (maxWeight == 0 || n == 0)
        return 0;

    if (weights[0] > maxWeight)
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);

    int inclusion = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
    int exclusion = knapsack(weights + 1, values + 1, n - 1, maxWeight);

    return max(inclusion, exclusion);
}

// Memoization: T.C: O(maxWeight * n) S.C: O(maxWeight * n)
int knapsack_mem(int *weights, int *values, int n, int maxWeight, int **output)
{
    // Base case
    if (n == 0 || maxWeight == 0)
        return 0;

    // If we have already computed the ans for this recursion call
    if (output[n][maxWeight] != -1)
        return output[n][maxWeight];

    int ans;
    // Inbound check
    if (weights[0] > maxWeight)
    {
        ans = knapsack_mem(weights + 1, values + 1, n - 1, maxWeight, output);
    }
    else
    {
        // recursion calls
        int inclusion = knapsack_mem(weights + 1, values + 1, n - 1, maxWeight - weights[0], output) + values[0];
        int exclusion = knapsack_mem(weights + 1, values + 1, n - 1, maxWeight, output);

        ans = max(inclusion, exclusion);
    }

    // save
    output[n][maxWeight] = ans;

    return output[n][maxWeight];
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **ans = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
        {
            ans[i][j] = -1;
        }
    }

    return knapsack_mem(weights, values, n, maxWeight, ans);
}

// D.P: T.C: O(maxWeight * n)  S.C: O(maxWeight * n)

int knapsack(int *weights, int *values, int n, int maxWeight)
{

    // Declared our dp matrix
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
    }

    // Filling first row as our base case
    for (int j = 0; j <= maxWeight; i++)
    {
        output[0][j] = 0;
    }

    // Filling first column as our base case
    for (int i = 0; i <= n; i++)
    {
        output[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (weights[n - i] > j)
            {
                output[i][j] = output[i - 1][j];
            }
            else
            {
                int inclusion = output[i - 1][j - weights[n - i]] + values[n - i];
                int exclusion = output[i - 1][j];

                output[i][j] = max(inclusion, exclusion);
            }
        }
    }

    return output[n][maxWeight];
}