#include <iostream>
#include <string>

// T.C.: exponential
int shortestSubsequenceRec(string a, string b, int siA, int siB)
{
    if (siB == b.size())
        return 1;
    if (siA == a.size())
        return INT_MAX; // No possible ans

    int exclusion = shortestSubsequenceRec(a, b, siA + 1, siB);
    int indexB = -1;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == a[siA])
        {
            indexB = i;
            break;
        }
    }

    if (indexB == -1)
        return 1;
    int inclusion = shortestSubsequenceRec(a, b, siA + 1, indexB + 1) + 1;

    return min(inclusion, exclusion);
}

// Memoization

int shortestSubsequenceMem(string a, string b, int siA, int siB, int **output)
{
    if (siB == b.size())
        return 1;
    if (siA == a.size())
        return INT_MAX; // No possible ans

    if (output[siA][siB] != -1)
        return output[siA][siB];

    int exclusion = shortestSubsequenceRec(a, b, siA + 1, siB, output);
    int indexB = -1;
    // This searching can be optimised using a mxn matrix
    // eg: 5th character in string "a" comes where in string "b" after its 6th index
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == a[siA])
        {
            indexB = i;
            break;
        }
    }

    if (indexB == -1)
        return 1;
    int inclusion = shortestSubsequenceRec(a, b, siA + 1, indexB + 1, output) + 1;

    output[siA][siB] = min(inclusion, exclusion);

    return output[siA][siB];
}

int shortestSubsequence(string a, string b)
{
    int m = a.size(), n = b.size(0);
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }

    int ans = shortestSubsequenceMem(a, b, siA, siB, output);
    for (int i = 0; i < m; i++)
    {
        delete[] output[i];
    }
    delete[] output;
    return ans;
}