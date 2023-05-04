#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;

// Hint: 1. Continious allocation 2. Minimum of max (lowest maximum)

bool isPossible(vector<int> &books, int m, int &mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i] > mid)
            return false;
        if (pageSum + books[i] <= mid)
        {
            pageSum += books[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m)
                return false;
            pageSum = books[i];
        }
    }

    return true;
}

int allocateBooks(vector<int> &books, int m)
{
    int start = 0;
    int end = accumulate(books.begin(), books.end());

    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(books, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}