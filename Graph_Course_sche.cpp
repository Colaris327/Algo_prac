// Leetcode 207
// https://leetcode.com/problems/course-schedule/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    // Topological sort version
    bool canFinish_topo(int numCourses, vector<vector<int>>& prerequisites)
    {
        // Use topological sort
        vector<int> In_degree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        queue<int> Q;
        int visited = 0;

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
            visited++;

            for (auto it : edges[current])
            {
                In_degree[it]--;
                if (In_degree[it] == 0)
                    Q.push(it);
            }
        }

        return visited == numCourses ? true : false;
    }

    // DFS version, Color: 0 is white, 1 is gray, 2 is black
    bool DFS(int current, vector<int>& Color, vector<vector<int>>& edges)
    {
        if (Color[current] == 1)
            return false;
        else if (Color[current] == 0)
        {
            Color[current] = 1;
            for (auto it : edges[current])
            {
                if (!DFS(it, Color, edges))
                    return false;
            }
            Color[current] = 2;
        }
        return true;
    }
    bool canFinish_DFS(int numCourses, vector<vector<int>>& prerequisites)
    {
        // use DFS to check cycle
        vector<int> Color(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        stack<int> S;

        // create adjencency list
        for (auto it : prerequisites)
            edges[it[1]].push_back(it[0]);

        for (int i = 0; i < numCourses; i++)
            if (Color[i] == 0)
            {
                if (!DFS(i, Color, edges))
                    return false;
            }
        return true;
    }
};