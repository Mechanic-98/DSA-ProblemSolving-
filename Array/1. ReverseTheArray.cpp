#include <iostream>
using namespace std;

void reverse(int *arr, int n)
{
    int start = 0, end = n - 1;
    while (start > end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
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