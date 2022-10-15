

int solveRec(vector<int> &num, int target, int minimumCoins)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int smallAns = solveRec(num, target - num[i], minimumCoins);
        if (smallAns != INT_MAX)
        {
            minimumCoins = min(minimumCoins, smallAns + 1);
        }
    }

    return minimumCoins;
}
int minimumElements(vector<int> &num, int x)
{
    int minimumCoins = INT_MAX;
    int ans = solveRec(num, x, minimumCoins);
    if (ans == INT_MAX)
        return -1;

    return ans;
}