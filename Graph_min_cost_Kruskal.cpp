// Leetcode 1584
// https://leetcode.com/problems/min-cost-to-connect-all-points/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class edge
{
    public:
        int start;
        int end;
        int weight;
};

class Compare{
    public:
        bool operator() (edge a, edge b) {return a.weight > b.weight;}
};
class Solution {
    public:
        vector<int> Set;
        int Find_set(int current)
        {
            int root = current;
            while(root != Set[root])
                root = Set[root];
            return root;
        }
        void Merge_set(int x, int y)
        {
            int root_of_x = Find_set(x);
            int root_of_y = Find_set(y);
            int new_root = root_of_x > root_of_y ? root_of_y : root_of_x;
            Set[root_of_x] = new_root;
            Set[root_of_y] = new_root;
        }
        int minCostConnectPoints(vector<vector<int>>& points)
        {
            for (int i = 0; i < points.size(); i++)
            {
                Set.push_back(i);
            }
            int count_edges = 0, total_weight = 0;
            priority_queue<edge, vector<edge>, Compare> Q;
            vector<int> Selected(points.size(), 0);
            vector<edge> Edges;

            // calculate all edges' weight
            for (int i = 0; i < points.size(); i++)
                for (int j = i + 1; j < points.size(); j++)
                {
                    edge tmp;
                    tmp.start = i;
                    tmp.end = j;
                    tmp.weight = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                    Q.push(tmp);
                }

            while (!Q.empty() && count_edges < points.size())
            {
                edge tmp = Q.top();
                Q.pop();
                if (Find_set(tmp.start) == Find_set(tmp.end))
                    continue;
                else
                {
                    Merge_set(tmp.start, tmp.end);
                    total_weight += tmp.weight;
                    count_edges++;
                }
            }
            return total_weight;
        }
};

int main()
{
    vector<vector<int>> arr = {{2, -3}, {-17, -8}, {13, 8}, {-17, -15}};
    Solution S;
    cout << S.minCostConnectPoints(arr) << endl;
}