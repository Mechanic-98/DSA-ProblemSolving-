/*
https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
    void dfs(int row, int col, vector<vector<int>> image, vector<vector<int>> &ans, int newColor,
             int initialColor, int dx[], int dy[])
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                image[newRow][newCol] == initialColor && ans[newRow][newCol] != newColor)
            {
                dfs(newRow, newCol, image, ans, newColor, initialColor, dx, dy);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;

        // left, up, right, down;
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, 1, 0, -1};
        dfs(sr, sc, image, ans, newColor, initialColor, dx, dy);
        return ans;
    }
};