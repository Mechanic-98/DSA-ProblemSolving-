

int maxMoneyLooted(int *arr, int n)
{

    /*
    Assuming that houses are numbered from 0 to n-1.
    maxMoney[i] -> max money that can be looted from houses numbered from 0 to n-1
    */
    int *maxMoney = new int[n];
    maxMoney[0] = arr[0];
    if (n >= 1)
        maxMoney[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        int inclusion = maxMoney[i - 2] + arr[i];
        int exclusion = maxMoney[i - 1];
        maxMoney[i] = max(inclusion, exclusion);
    }

    int result = maxMoney[n - 1];

    delete[] maxMoney;

    return result;
}