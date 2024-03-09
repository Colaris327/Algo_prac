// Leetcode #1710
// https://leetcode.com/problems/maximum-units-on-a-truck/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {return a[1] > b[1];} 

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int profit = 0;
        for (auto i : boxTypes)
        {
            if (truckSize <= i[0])
            {
                profit += truckSize * i[1];
                break;
            }
            else
            {
                profit += i[0]*i[1];
                truckSize -= i[0];
            }
        }
        return profit;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> boxes = {{1, 3}, {2, 2}, {3, 1}};
    cout << S.maximumUnits(boxes, 4) << endl;
    return 0;
}