// Leetcode #435
// https://leetcode.com/problems/non-overlapping-intervals/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> b) {return  a[1] < b[1];}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int current = INT_MIN, remove_count = 0;
        for (auto i : intervals)
        {
            if (i[0] >= current)
                current = i[1];
            else
                remove_count++;
        }
        return remove_count;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    Solution S;
    cout << S.eraseOverlapIntervals(intervals) << endl;
    return 0;
}