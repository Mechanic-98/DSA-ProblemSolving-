#include <cmath>

// Recursion
int getAllWaysRec(int a, int b, int i)
{
    // Write your code here
    if (a == 0)
        return 1;
    if (a < 0 || i * i > a)
        return 0;

    int contrinutionByI = (int)(pow(i, b));
    int included = getAllWaysRec(a - contrinutionByI, b, i + 1);
    int excluded = getAllWaysRec(a, b, i + 1);

    return included + excluded;
}

int getAllWays(int a, int b)
{

    return getAllWaysRec(a, b, 1);
}

// Memoization

int getAllWaysMem(int a, int b, int **output)
{
}