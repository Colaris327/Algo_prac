// Leetcode 169
// https://leetcode.com/problems/majority-element/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int max_count = 0, count = 0, max_num = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (count > max_count)
                {
                    max_count = count;
                    max_num = nums[i - 1];
                }
                count = 0;
            }
            count++;
        }
        if (count > max_count)
            max_num = *(nums.end() - 1);
        return max_num;
    }
    // another solution: after sorting, just return nums[length / 2]
    // another linear time solution: MJRTY — A Fast Majority Vote Algorithm
};

int main()
{
    Solution S;
    std::vector<int> arr = {3, 4, 3};
    std::cout << S.majorityElement(arr)<< std::endl;
    return 0;
}