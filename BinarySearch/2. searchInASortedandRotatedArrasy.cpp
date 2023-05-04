#include <vector>
#include <iostream>
using namespace std;

// Approach 1: find pivot and check in which part the target lies and apply BS
/*
Approach 2:
    1. find mid, now either one left or right part of the mid must be sorted
    2. If target lies in the sorted part, apply BS else discard that part.
*/

class Solution2
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);

            // check for mid
            if (nums[mid] == target)
            {
                ans = mid;
                return ans;
            }

            /* Either of the one half of this mid must be sorted */

            // check if left is sorted
            if (nums[0] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target <= nums[high] && target > nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};