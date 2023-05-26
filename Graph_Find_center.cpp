// Leetcode 1791
// https://leetcode.com/problems/find-center-of-star-graph/
// Compare to Find Judge Problem, this problem is undirected graph
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int findCenter(vector<vector<int>>& edges)
    {
        int n = edges.size() + 1;
        vector<int> Degree(n + 1, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            Degree[edges[i][0]]++;
            Degree[edges[i][1]]++;
        }

        for(int i = 1; i <= n; i++)
            if (Degree[i] == n - 1)
                return i;

        return -1;
    }
};