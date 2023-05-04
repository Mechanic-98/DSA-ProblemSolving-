// https://leetcode.com/problems/majority-element-ii/

#include <vector>
using namespace std;

/*
Note: Majority element  = element's count > floor(n/3)
    thus, at max we can have 2 majority elements

Approach: Boyer Moore's Voting Algo O(N)
    Initially count1 = 0, element1 = -1 and count2 = 0, element2 = -1;
    if(arr[i] == element1) count1++;
    else if(arr[i] == element2) count2++;
    else if (count1 == 0){
        element1 = arr[i];
        count1 = 1;
    } else if (count2 == 0){
        element2 = arr[i];
        count2 = 1;
    } else {
        count1--;
        count2--;
    }

O(N)
This algo gives majority elements but to check if they comply with our
requirement of majority;
    we need to check if element1 and element2 are occuring more than floor(n/3)
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int numberOfElements = nums.size();
        int element1 = -1, element2 = -1, count1 = 0, count2 = 0;

        for (int i = 0; i < numberOfElements; i++)
        {
            if (nums[i] == element1)
                count1++;
            else if (nums[i] == element2)
                count2++;
            else if (count1 == 0)
            {
                element1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                element2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < numberOfElements; i++)
        {
            if (nums[i] == element1)
                count1++;
            else if (nums[i] == element2)
                count2++;
        }

        if (count1 > numberOfElements / 3)
            ans.push_back(element1);
        if (count2 > numberOfElements / 3)
            ans.push_back(element2);

        return ans;
    }
};