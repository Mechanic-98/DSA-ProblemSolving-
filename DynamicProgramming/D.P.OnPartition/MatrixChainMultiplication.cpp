#include <iostream>
#include <cmath>
using namespace std;

// Recursion T.C.: O(N^N)
int matrixChainMultiplicationRec(int *arr, int start, int end)
{
    if (end - start == 1)
        return 0; // Single matrix means no multiplication operation will happen

    int minimumOp = INT_MAX;

    for (int partitionIndex = start + 1; partitionIndex <= end - 1; partitionIndex++)
    {
        int firstPart = matrixChainMultiplicationRec(arr, start, partitionIndex);
        int secondPart = matrixChainMultiplicationRec(arr, partitionIndex, end);

        int operationsForTwoPortions = arr[start] * arr[partitionIndex] * arr[end];

        int ans = firstPart + secondPart + operationsForTwoPortions;

        minimumOp = min(minimumOp, ans);
    }

    return minimumOp;
}

// Memoization  T.C.: O(N^2)

int matrixChainMultiplicationMem(int *arr, int start, int end, int **dp)
{
    if (end - start == 1)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int minimumOp = INT_MAX;

    for (int partitionIndex = start + 1; partitionIndex <= end - 1; partitionIndex++)
    {
        int firstPart = matrixChainMultiplicationMem(arr, start, partitionIndex, dp);
        int secondPart = matrixChainMultiplicationMem(arr, partitionIndex, end, dp);

        int operationsForTwoPortions = arr[start] * arr[partitionIndex] * arr[end];

        int ans = firstPart + secondPart + operationsForTwoPortions;

        minimumOp = min(minimumOp, ans);
    }

    dp[start][end] = minimumOp;

    return dp[start][end];
}

// DP
int matrixChainMultiplicationDP(int *arr, int n)
{
    // int **dp = new int[n]; // start range (0 -> n-1)
    // for (int = 0; i < n; i++)
    // {
    //     dp[i] = new int[n]; // end range (1 -> n)
    // }

    // // Base case
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (j - i <= 1)
    //             dp[i][j] = 0;
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 2; j <= n; j++)
    //     {
    //         dp[i][j] = INT_MAX;
    //         for (int partitionIndex = i + 1; partitionIndex <= j - 1; k++)
    //         {
    //             int ans = dp[i][partitionIndex] + dp[partitionIndex][j] +
    //                       (arr[i] * arr[partitionIndex] * arr[j]);
    //             dp[i][j] = min(dp[i][j], ans);
    //         }
    //     }
    // }

    // return dp[0][n];

    /* For simplicity of the program, one
    extra row and one extra column are
    allocated in m[][]. 0th row and 0th
    column of m[][] are not used */
    int m[n][n];

    int i, j, k, L, q;

    /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */

    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int matrixChainMultiplication(int *arr, int n)
{
    if (n <= 1)
        return 0;

    // return matrixChainMultiplicationRec(arr, 0, n); -> Recurive solution

    /* Memoization solution
    int **dp = new int *[n]; // start range (0 -> n-1)
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n + 1]; // end range (1 -> n)
        for (int j = 0; j <= n; j++)
        {
            dp[i] = -1;
        }
    }

    return matrixChainMultiplicationMem(arr, 0, n, dp);
    */

    return matrixChainMultiplicationDP(arr, n);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}