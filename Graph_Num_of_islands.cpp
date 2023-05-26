// Leetcode 200
// https://leetcode.com/problems/number-of-islands/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int row = grid.size();
        int column = grid[0].size();
        int count = 0;
        queue<pair<int, int>> Q;
        vector<vector<char>> copy_grid = grid;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                if (copy_grid[i][j] == '1')
                {
                    count++;
                    copy_grid[i][j] = '0';
                    Q.push(make_pair(i, j));
                    while (!Q.empty())
                    {
                        int i = Q.front().first;
                        int j = Q.front().second;
                        Q.pop();

                        if (i - 1 >= 0 && copy_grid[i - 1][j] == '1')
                        {
                            Q.push(make_pair(i - 1, j));
                            copy_grid[i - 1][j] = '0';
                        }
                        if (i + 1 < row && copy_grid[i + 1][j] == '1')
                        {
                            Q.push(make_pair(i + 1, j));
                            copy_grid[i + 1][j] = '0';
                        }
                        if (j - 1 >= 0 && copy_grid[i][j - 1] == '1')
                        {
                            Q.push(make_pair(i, j - 1));
                            copy_grid[i][j - 1] = '0';
                        }
                        if (j + 1 < column && copy_grid[i][j + 1] == '1')
                        {
                            Q.push(make_pair(i, j + 1));
                            copy_grid[i][j + 1] = '0';
                        }
                    }
                }
            }    

        return count;
    }
};