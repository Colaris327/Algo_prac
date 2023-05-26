// Leetcode 733
// 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int row = image.size();
        int column = image[0].size();
        queue<pair<int, int>> Q;
        int Start_color = image[sr][sc];
        if (Start_color == color)
            return;

        Q.push(make_pair(sr, sc));
        while (!Q.empty())
        {
            int i = Q.front().first;
            int j = Q.front().second;
            image[i][j] = color;
            Q.pop();

            // this place is wrong, we should set image[i - 1][j] = color when we push into queue
            if (i - 1 >= 0 && image[i - 1][j] == Start_color)
                Q.push(make_pair(i - 1, j));
            if (i + 1 < row && image[i + 1][j] == Start_color)
                Q.push(make_pair(i + 1, j));
            if (j - 1 >= 0 && image[i][j - 1] == Start_color)
                Q.push(make_pair(i, j - 1));
            if (j + 1 < column && image[i][j + 1] == Start_color)
                Q.push(make_pair(i, j + 1));
        }
    }
};