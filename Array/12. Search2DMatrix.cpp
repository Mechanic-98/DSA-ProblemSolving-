// https://leetcode.com/problems/search-a-2d-matrix/description/

#include <vector>
using namespace std;

/*
Approach:
    Mark every place in matrix as linear indexed from low = 0 to high = (n*m -1)
    Perform binary search -> mid = low + (high - low)/2
    rowForMid = mid / m(columns) and colForMid = mid % m(colums)
    Go on like this O(log(n*m))
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (!matrix.size())
            return false;

        int rows = matrix.size(), columns = matrix[0].size();
        int low = 0, high = (rows * columns) - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int currentRow = mid / columns, currentCol = mid % columns;

            if (matrix[currentRow][currentCol] == target)
                return true;
            if (matrix[currentRow][currentCol] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};

// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

/*
Approach:
    As both rows and cols are sorted;
    if target is smaller move left and if greater move down
*/
class Solution2
{
public:
    bool searchMatrix2(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size(), columns = matrix[0].size();
        int currentRowIndex = 0, currentColumnIndex = columns - 1;

        while (currentRowIndex < rows && currentColumnIndex >= 0)
        {
            if (matrix[currentRowIndex][currentColumnIndex] == target)
                return true;
            else if (matrix[currentRowIndex][currentColumnIndex] > target)
                currentColumnIndex--;
            else
                currentRowIndex++;
        }

        return false;
    }
};