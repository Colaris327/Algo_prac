// LeetCode #274
#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
    public:
        int H_index(std::vector<int>& arr)
        {
            std::sort(arr.begin(), arr.end(), std::greater<int>());

            // binary search
            int index = arr.size() / 2;
            int left = 0, right = arr.size() - 1;
            if (arr[0] == 0)
                return 0;

            while (index < arr.size() && index != left)
            {
                if (arr[index] == index + 1)
                    break;
                else if (arr[index] > index + 1)
                {
                    left = index;
                    index = (right + index) / 2;
                }
                else
                {
                    right = index;
                    index = (left + right) / 2;
                }
            }
            // because of using binary search, we need to check the situation of
            if (index == arr.size() - 2 && index + 1 < arr[index + 1])
                return index + 2;
            else
                return index + 1;
        }
};

int main()
{
    Solution S;
    std::vector<int> arr = {3, 0, 6, 1, 5, 9, 10, 2, 4, 2, 5};
    std::cout << S.H_index(arr) << std::endl;
    return 0;
}