#include <vector>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/find-peak-element/description/

// Same code for finding pivot index in a sorted array
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] < nums[mid + 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return start;
    }
};