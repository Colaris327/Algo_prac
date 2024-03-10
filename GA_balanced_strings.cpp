// Leetcode #1221
// https://leetcode.com/problems/split-a-string-in-balanced-strings/description/
#include <iostream>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int count_L = 0, num_of_str = 0;
        for (auto c : s)
        {
            if (c == 'L')
                count_L++;
            else if (c == 'R')
                count_L--;
            
            if (count_L == 0)
                num_of_str++;
        }
        return  num_of_str;
    }
};