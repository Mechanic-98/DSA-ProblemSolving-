// https://leetcode.com/problems/merge-intervals/

// check if intvals are sorted or not

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0)
        return mergedIntervals;

    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];

    for (auto interval : intervals)
    {
        if (interval[0] <= tempInterval[1])
        {
            tempInterval[1] = max(interval[1], tempInterval[1]);
        }
        else
        {
            mergedIntervals.push_back(tempInterval);
            tempInterval = interval;
        }
    }

    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}