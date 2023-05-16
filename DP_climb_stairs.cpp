// Leetcode #746
// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> stairs(cost.size(), 0);
        if (stairs.size() < 2)
            return 0;
        
        stairs[0] = cost[0];
        stairs[1] = cost[1];
        for (int i = 2; i < stairs.size(); i++)
            stairs[i] = min(stairs[i - 1], stairs[i - 2]) + cost[i];

        return min(stairs[stairs.size() - 1], stairs[stairs.size() - 2]);
    }
};

int main()
{
    Solution S;
    vector<int> seq = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << S.minCostClimbingStairs(seq);

    return 0;
}