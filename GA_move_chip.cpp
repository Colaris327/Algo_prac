// Leetcode #1217
// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int count[] = {0, 0};
        for (auto i : position)
            count[i % 2]++;
        return  min(count[0], count[1]);
    }
};