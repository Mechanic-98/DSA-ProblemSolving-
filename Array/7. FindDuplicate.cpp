// https://leetcode.com/problems/find-the-duplicate-number/

/*
Approach1: sort O(NlogN) O(1)
Approach2: hashing O(N) O(N)
Approach3: LinkedList cycle method (Slow and fast pointer)
*/

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];

    do
    {
        slow = nums[slow];       // by 1
        fast = nums[nums[fast]]; // by 2
    } while (slow != fast);

    fast = nums[0];

    while (slow != fast)
    {
        slow = nums[slow]; // by 1
        fast = nums[fast]; // by 1
    }

    return slow;
}