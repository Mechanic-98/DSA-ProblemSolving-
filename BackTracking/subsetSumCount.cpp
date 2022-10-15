#include <iostream>
using namespace std;

int subSetSumCount(long long *arr, int n, long long target, int count)
{
    if (n == 0)
    {
        if (target == 0)
            count++;
        return count;
    }

    int included = subSetSumCount(arr + 1, n - 1, target - arr[0], count);
    int excluded = subSetSumCount(arr + 1, n - 1, target, count);

    return included + excluded;
}

int main()
{

    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        int sizeOfArray;
        long long target;
        cin >> sizeOfArray >> target;

        long long *arr = new long long[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++)
        {
            cin >> arr[i];
        }
        cout << subSetSumCount(arr, sizeOfArray, target, 0) << endl;
    }
    return 0;
}