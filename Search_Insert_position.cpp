// LeetCode 35
// https://leetcode.com/problems/search-insert-position/
#include <iostream>
#include <vector>

class Solution
{
    public:
        int searchInsert(std::vector<int>& nums, int target)
        {
            int left = 0, right = nums.size() - 1, mid;
            while (left < right)
            {
                mid = (left + right) >> 1;
                if (nums[mid] == target)
                    break;
                else if (nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if (nums[(left + right) / 2] < target)
                return (left + right) / 2 + 1;
            else
                return (left + right) / 2;
        }
};

int main()
{
    Solution S;
    std::vector<int> arr = {1, 3, 5, 6};
    std::cout << S.searchInsert(arr, 0);
    return 0;
}