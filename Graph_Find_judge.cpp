// LeetCode 997
// https://leetcode.com/problems/find-the-town-judge/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int findJudge(int n, vector<vector<int>>& trust)
    {
        // only need to count the degree, don't create adjacency matrix
        vector<int> In_degree(n + 1, 0);
        vector<int> Out_degree(n + 1, 0);

        for (int i = 0; i < trust.size(); i++)
        {
            In_degree[trust[i][1]]++;
            Out_degree[trust[i][0]]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if (In_degree[i] == n - 1 && Out_degree[i] == 0)
                return i;
        }
        return -1;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> arr = {{1, 3}, {2, 3}};

    cout << Solution::findJudge(n, arr) << endl;
    return 0;
}