#include <iostream>
#include <vector>
using namespace std;

/* Dutch flag algo
1. if nums[mid] == 0; swap nums[low] and nums[mid], low++ mid++;
2. if nums[mid] == 1; mid++;
3. if nums[mid] == 2; swap nums[high] and nums[mid], high--;
*/

void sort012(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[low++], nums[mid++]);
            break;
        case 1:
            mid++;
            break;

        case 2:
            swap(nums[high--], nums[mid]);
            break;
        }
    }
}