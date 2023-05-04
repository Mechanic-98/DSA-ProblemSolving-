// https://leetcode.com/problems/powx-n/

#include <vector>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long newN = n;
        if (newN < 0)
            newN = -1 * newN;

        while (newN)
        {
            if (newN % 2)
            {
                ans = ans * x;
                newN = newN - 1;
            }
            else
            {
                x = x * x;
                newN = newN / 2;
            }
        }

        if (n < 0)
            ans = (double)(1.0) / (double)ans;
        return ans;
    }
};