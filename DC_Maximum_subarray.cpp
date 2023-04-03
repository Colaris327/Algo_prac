// LeetCode #53
// https://leetcode.com/problems/maximum-subarray/
// using recursive
#include <iostream>
#include <vector>

class Solution
{
    public:
        int maxSubArray(std::vector<int>& nums) {return max_sub(nums, 0, nums.size() - 1);}
        int max_sub(std::vector<int>& nums, int left, int right)
        {
            if (left == right)
                return nums[left];
            int mid = (left + right) / 2;
            int max_left = max_sub(nums, left, mid);
            int max_right = max_sub(nums, mid + 1, right);

            int mid_left_side = INT32_MIN, mid_right_side = INT32_MIN;
            int temp = 0;
            for (int i = mid; i >= left; i--)
            {
                temp += nums[i];
                if (temp > mid_left_side)
                    mid_left_side = temp;
            }
            temp = 0;
            for (int i = mid + 1; i <= right; i++)
            {
                temp += nums[i];
                if (temp > mid_right_side)
                    mid_right_side = temp;
            }

            int max_mid = mid_left_side + mid_right_side;
            if (max_left >= max_mid && max_left >= max_right)
                return max_left;
            else if (max_right >= max_left && max_right >= max_mid)
                return max_right;
            else
                return max_mid;
        }
};

int main()
{
    Solution S;
    std::vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << S.maxSubArray(arr);
    return 0;
}