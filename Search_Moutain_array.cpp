// LeetCode 852
// 
#include <iostream>
#include <vector>

class Solution
{
    public:
        int peakIndexInMountainArray(std::vector<int>& arr);
};

int main()
{
    Solution S;
    std::vector<int> arr = {0, 10, 5, 2};
    std::cout << S.peakIndexInMountainArray(arr);
    return 0;
}

int Solution::peakIndexInMountainArray(std::vector<int>& arr)
{
    int left = 0, right = arr.size(), mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            break;
        if (arr[mid] > arr[mid + 1])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (left + right) >> 1;
}