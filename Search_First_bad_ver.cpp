// LeetCode 278
// https://leetcode.com/problems/first-bad-version/
#include <iostream>

// the answer
int bad;
bool isBadVersion(int n) {return n >= bad;}

class Solution
{
    public:
        int firstBadVersion(int n)
        {
            unsigned int left = 1, right = n, mid;
            while (left < right)
            {
                mid = (left + right) / 2;
                if (isBadVersion(mid) && !isBadVersion(mid - 1))
                    return mid;
                else if (isBadVersion(mid))
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return left;
        }
};

int main()
{
    bad = 4;
    Solution S;
    std::cout << S.firstBadVersion(5);
    return 0;
}