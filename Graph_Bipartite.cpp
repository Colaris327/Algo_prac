// Leetcode 785
// https://leetcode.com/problems/is-graph-bipartite/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Color: -1 is non-visited, 0 is white, 1 is black. If nearby two vertices have same color, the graph is not bipartite.
    bool DFS(int prev_vertex, int current_vertex, vector<int>& Color, vector<vector<int>>& edges)
    {
        if (Color[current_vertex] == -1)
        {
            Color[current_vertex] = !Color[prev_vertex];
            for (auto it : edges[current_vertex])
            {
                if (!DFS(current_vertex, it, Color, edges))
                    return false;
            }
        }
        else
        {
            if (Color[current_vertex] == Color[prev_vertex])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> Color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (Color[i] == -1)
            {
                for (auto it : graph[i])
                {
                    if (!DFS(i, it, Color, graph))
                        return false;
                }
            }
        }
        return true;
    }
};