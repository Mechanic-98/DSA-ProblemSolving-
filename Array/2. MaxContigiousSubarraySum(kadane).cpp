#include <iostream>
using namespace std;

int maxSubArraySum(int *arr, int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // step 1 add element to currentSum
        currentSum = currentSum + arr[i];

        // step 2 find max
        maxSum = max(maxSum, currentSum);

        // discard subaaray till now, if current sum < 0
        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr[i] = element;
    }

    reverse(arr, n);
}