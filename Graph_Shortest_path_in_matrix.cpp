// Leetcode 1091
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid.size();
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1)
            return -1;

        // preprocess, avoid confusion
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                    grid[i][j] = -1;
                else
                    grid[i][j] = INT32_MAX;
            }

        int dir_x[] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dir_y[] = {1, -1, 0, 1, -1, 1, 0, -1};

        queue<pair<int, int>> Q;
        grid[0][0] = 1;
        Q.push(make_pair(0, 0));
        while (!Q.empty())
        {
            int x = Q.front().first;
            int y = Q.front().second;
            int distance = grid[x][y];
            Q.pop();
            for (int i = 0; i < 8; i++)
            {
                int new_x = x + dir_x[i];
                int new_y = y + dir_y[i];
                if (new_x < 0 || new_y < 0)
                    continue;
                if (new_x >= row || new_y >= col)
                    continue;
                if (grid[new_x][new_y] == -1)
                    continue;

                if (distance + 1 < grid[new_x][new_y])
                {
                    grid[new_x][new_y] = distance + 1;
                    Q.push(make_pair(new_x, new_y));
                }
            } 
        }
        return grid[row - 1][col - 1] == INT32_MAX ? -1 : grid[row - 1][col - 1];
    }
};