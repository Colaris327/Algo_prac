// LeetCode #88
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        //merge two sorted array nums1 and nums2 into nums1, the length of sorted array is m
        void Merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
        {
            vector<int> data_nums1 = nums1;
            int nums1_index = 0, nums2_index = 0, i = 0;
            while (nums1_index < m && nums2_index < n)
            {
                if (data_nums1[nums1_index] <= nums2[nums2_index])
                    nums1[i++] = data_nums1[nums1_index++];
                else
                    nums1[i++] = nums2[nums2_index++];
            }
            if (nums2_index < n)
                while (nums2_index < n)
                    nums1[i++] = nums2[nums2_index++];
            else
                while (nums1_index < m)
                    nums1[i++] = data_nums1[nums1_index++];
        }
};

int main()
{
    Solution S;
    vector<int> sample1_nums1 = {1, 2, 3, 0, 0, 0};
    int m1 = 3;
    vector<int> sample1_nums2 = {2, 5, 6};
    int n1 = 3;
    S.Merge(sample1_nums1, m1, sample1_nums2, n1);
    for (int i = 0; i < sample1_nums1.size(); i++)
        cout << sample1_nums1[i] << ' ';
    cout << endl;
}