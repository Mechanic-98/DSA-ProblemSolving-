// https://leetcode.com/problems/rotate-image/

/*
Concept:
    Transpose

Approach:
    Step 1: Calculate transpose O(N*N)
    Step 2: Revrese every row O(N*N)
*/
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Revrese every row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};