
// Recursion: T.C: O(2^n)  S.C: O(1)
int LIS(int arr[], int n, int prev)
{
    // Base case: if nothing is remaining
    if (n == 0)
        return 0;

    // case 1: exclude the current element and process the
    // remaining elements
    int exclude = LIS(arr + 1, n - 1, prev);

    // case 2: include the current element if it is greater
    // than previous element in LIS
    int include = 0;
    if (arr[0] > prev)
        include = 1 + LIS(arr + 1, n - 1, arr[0]);

    // return maximum of above two choices
    return max(include, exclude);
}

int longestIncreasingSubsequence(int *arr, int n)
{
    int prev = INT_MIN;
    return LIS(arr, n, prev);
}

// Memoization

int LIS_MEM(int *arr, int n, int curIndex, int prevIndex, int **output)
{
    if (curIndex == n)
        return 0;

    // Coordinate calibration: output[curIndex][prevIndex + 1] stores LIS for
    // index: curIndex and prevIndex: prevIndex not prevIndex + 1.
    if (output[curIndex][prevIndex + 1] != -1)
    {
        return output[curIndex][prevIndex + 1];
    }

    int exclude = LIS_MEM(arr, n, curIndex + 1, prevIndex, output);
    int include = 0;
    if (prevIndex == -1 || arr[curIndex] > arr[prevIndex])
    {
        include = 1 + LIS_MEM(arr, n, curIndex + 1, curIndex, output);
    }

    output[curIndex][prevIndex + 1] = max(include, exclude);

    return output[curIndex][prevIndex + 1];
}

int longestIncreasingSubsequenceMem(int *arr, int n)
{
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return LIS_MEM(arr, n, 0, -1, output);
}

// DP

int longestIncreasingSubsequence(int *arr, int n)
{
    int *output = new int[n];
    output[0] = 1;
    int finalAns = 1;

    for (int i = 1; i < n; i++)
    {
        int max = 1; // Even if we didn't found any valid j
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                int possibleAns = output[j] + 1;
                if (possibleAns > max)
                    max = possibleAns;
            }
        }
        output[i] = max;
        if (finalAns < output[i])
            finalAns = output[i];
    }

    return finalAns;
}
