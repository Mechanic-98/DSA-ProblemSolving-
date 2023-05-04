// https://leetcode.com/problems/pascals-triangle/

/*
Concept: Element at rth row and cth col of pascals triangle = (r-1) C (c-1)
            -> (r-1)! / (c-1)! => O(N)
*/

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};