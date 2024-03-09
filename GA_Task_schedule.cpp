// Leetcode #621
// https://leetcode.com/problems/task-scheduler/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (auto i : tasks)
            count[i - 'A']++;
        
        int max = 0, max_numbers = 0;
        for (auto i : count)
        {
            if (max < i)
            {
                max = i;
                max_numbers = 1;
            }
            else if (max == i)
                max_numbers++;
        }

        int value = (max - 1) * (n + 1) + max_numbers;
        return value < tasks.size() ? tasks.size() : value;
    }
};