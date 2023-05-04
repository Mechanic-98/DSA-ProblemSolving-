// https://leetcode.com/problems/majority-element/

#include <vector>
#include <unordered_map>
using namespace std;

/*
Moore's Voting Algo: (Priciple of cancelling)
    Initially take count = 0 and element = 0;
    Traverse linearly from start and check
    if(count == 0) element = arr[i];
    if(element == arr[i]) count++;
    else count--;

Note: it is applicable here as we are defining majority by
        element having count > n/2
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, element = 0;

        for (int num : nums)
        {
            if (count == 0)
                element = num;
            if (num == element)
                count++;
            else
                count--;
        }

        return element;
    }
};