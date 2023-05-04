#include <vector>
#include <iostream>
using namespace std;

// Concept: Search space

class Solution
{
public:
    long long sqrtBS(int x)
    {
        int start = 0, end = x;

        long long ans = -1;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;

            long long square = mid * mid;

            if (square == x)
                return mid;
            else if (square < x)
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

    int mySqrt(int x)
    {
        return sqrtBS(x);
    }
};