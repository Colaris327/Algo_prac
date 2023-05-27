// Leetcode 210
// https://leetcode.com/problems/course-schedule-ii/
// This problem is modified from Course Schedule(Leetcode 207)
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        // Use topological sort
        vector<int> In_degree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        queue<int> Q;
        int visited = 0;
        vector<int> Topo_arr(numCourses);

        // caculate degree and create adjencency list
        for (auto it : prerequisites)
        {
            In_degree[it[0]]++;
            edges[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < numCourses; i++)
            if (In_degree[i] == 0)
                Q.push(i);

        while (!Q.empty())
        {
            int current = Q.front();
            Q.pop();
            Topo_arr[visited] = current;
            visited++;

            for (auto it : edges[current])
            {
                In_degree[it]--;
                if (In_degree[it] == 0)
                    Q.push(it);
            }
        }

        return visited == numCourses ? Topo_arr : vector<int>(0);
    }
};