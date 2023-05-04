#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;

// Hint: maxima of minima

// O(N)
bool isPossible(vector<int> &stalls, int k, int &mid)
{
    int cowsCount = 1, coordinateOfCowPlaced = stalls[0];

    for (int i = 1; i < stalls.size() - 1; i++)
    {
        if (stalls[i] - coordinateOfCowPlaced >= mid)
        {
            cowsCount++;
            coordinateOfCowPlaced = stalls[i];
        }
        if (cowsCount == k)
            return true;
    }

    return false;
}

// O(N * logN)
int agressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 1; // minimum distance will be atleast one
    int end = stalls[stalls.size() - 1] - stalls[0];

    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}