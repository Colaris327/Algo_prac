// Leetcode #1094
// https://leetcode.com/problems/car-pooling/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int location[1001] = {0};

        for (auto  trip : trips)
            for (int i = trip[1]; i != trip[2]; i++)
                location[i] += trip[0];

        for (auto i : location)
            if (i > capacity)
                return false;

        return true;
    }

    bool carPooling_2(vector<vector<int>>& trips, int capacity) {
        int location[1001] = {0};

        for (auto  trip : trips)
        {
            location[trip[1]] += trip[0];
            location[trip[2]] -= trip[0];
        }
        
        for (auto i : location)
        {
            capacity -= i;
            if (capacity < 0)
                return false;
        }

        return true;
    }
};