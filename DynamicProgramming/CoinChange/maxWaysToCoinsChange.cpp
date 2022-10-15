
// Recursion
int countWaysToMakeChangeRec(int denominations[], int numDenominations, int value)
{
    // Write your code here
    if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (numDenominations <= 0)
        return 0;

    int included = countWaysToMakeChangeRec(denominations, numDenominations, value - denominations[0]);
    int excluded = countWaysToMakeChangeRec(denominations + 1, numDenominations - 1, value);

    return included + excluded;
}

/*
There is an issue with the above solution.
The below solution doesn’t always return distinct sets.
For example, for set {1, 2, 3},
it returns 7 as some ways are permutations of each other, as shown below:

{1, 1, 1, 1}
{1, 1, 2}, {2, 1, 1}, {1, 2, 1}
{2, 2}
{1, 3}, {3, 1}
*/
int countWaysToMakeChangeRec2(int denominations[], int numDenominations, int value)
{
    // Write your code here
    if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    int count = 0;
    for (int i = 0; i < numDenominations; i++)
    {
        int smallAns = countWaysToMakeChange(denominations, numDenominations, value - denominations[i]);
        count += smallAns;
    }

    return count;
}

// Memoization

int countWaysToMakeChangeMem(int denominations[], int numDenominations, int value, int **output)
{
    if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (numDenominations <= 0)
        return 0;

    if (output[numDenominations][value] != -1)
        return output[numDenominations][value];

    int included = countWaysToMakeChangeMem(denominations, numDenominations, value - denominations[0], output);
    int excluded = countWaysToMakeChangeMem(denominations + 1, numDenominations - 1, value, output);

    output[numDenominations][value] = included + excluded;

    return output[numDenominations][value];
}

int countWaysToMakeChangeMem(int denominations[], int numDenominations, int value)
{
    int **output = new int *[numDenominations + 1];
    for (int i = 0; i <= numDenominations; i++)
    {
        output[i] = new int[value + 1];
        for (int j = 0; j <= value; j++)
        {
            output[i][j] = -1;
        }
    }

    int ans = countWaysToMakeChangeMem(denominations, numDenominations, value, output);
    delete[] output;
    return ans;
}

// DP

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **output = new int *[numDenominations];
    int include, exclude;
    for (int i = 0; i < numDenominations; i++)
    {
        output[i] = new int[value + 1];
    }

    for (int i = 0; i < numDenominations; i++)
    {
        output[i][0] = 1;
    }

    for (int i = 0; i < numDenominations; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            include = (j - denominations[i] >= 0) ? output[i][j - denominations[i]] : 0;
            exclude = (i >= 1) ? output[i - 1][j] : 0;
            output[i][j] = include + exclude;
        }
    }

    int ans = output[numDenominations - 1][value];

    delete[] output;
    return ans;
}