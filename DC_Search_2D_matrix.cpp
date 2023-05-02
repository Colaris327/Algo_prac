// Leetcode 240
// https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/943110778/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target)
        {
            if (matrix.size() == 0)
                return false;
            int height = matrix.size();
            int width = matrix[0].size();

            int i = 0, j = width - 1;// start at right top
            bool flag = false;
            while (i >= 0 && i < height && j >= 0 && j < width)
            {
                // because of the matrix's characteristic, if we start at right top, we can use comparison to decide going left or going down.
                if (matrix[i][j] == target)
                {
                    flag = true;
                    break;
                }
                else if (matrix[i][j] > target)
                    j--;
                else
                    i++;
            }
            return flag;
        }
};

int main()
{
    Solution S;
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                    {2, 5, 8, 12, 19},
                                    {3, 6, 9, 16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}};
    cout << S.searchMatrix(matrix, 5) << endl;
    return 0;
}