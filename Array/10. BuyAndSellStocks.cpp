// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
Approach1: Use currMinimum and currentProfit O(N)
Approach2: Using stack (NearestGreater to right) O(N)
*/

#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currentMaxProfit = 0, currentMinimumPrice = INT_MAX;

        for (auto price : prices)
        {
            currentMinimumPrice = min(currentMinimumPrice, price);
            currentMaxProfit = max(currentMaxProfit, price - currentMinimumPrice);
        }

        return currentMaxProfit;
    }
};