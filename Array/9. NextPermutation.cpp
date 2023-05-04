// https://leetcode.com/problems/next-permutation/

/*
Step1: Traverse from the end and find element such that arr[i] < arr[i+1]. O(N)

if(no such i is found) {
    skip step 2 and 3 and just reverse;
    as that means we are trying to find next permutation of the last permutation
}

Step2: Again traverse from the end to find element greater than element found in step1
        i.e. arr[j] > arr[i] O(N)
Step3: Swap(arr[i], arr[j])
Step4: Reverse(arr + i + 1, arr + n) O(N)
*/

#include <vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), i, j;

        // Step 1
        for (i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
                break;
        }

        if (i < 0)
            // Skipping step 2 and 3 and executing Step 4
            reverse(nums.begin(), nums.end());
        else
        {
            // Step 2
            for (j = n - 1; j >= i; j--)
            {
                if (nums[j] > nums[i])
                    break;
            }

            // Step 3
            swap(nums[i], nums[j]);

            // Step 4
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};