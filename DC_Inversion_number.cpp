// APCS 2018/06 P4
// https://judge.tcirc.tw/ShowProblem?problemid=d064
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Inversion(vector<int> &arr, int left, int right)
{
    // if (arr.size() <= 1)
    //     return 0;
    // else if (arr.size() == 2)
    //     return arr[0] > arr[1];

    // // don't use this, use absolute median might cause forever loop like {3, 2, 3}
    // // vector<int> tmp = arr;
    // // sort(tmp.begin(), tmp.end());
    // // int median = tmp[tmp.size() / 2];

    // int max = INT32_MIN, min = INT32_MAX;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] > max)
    //         max = arr[i];
    //     if (arr[i] < min)
    //         min = arr[i];
    // }
    // // all elements are same
    // if (max == min)
    //     return 0;
    // // median is an important part, must prevent from causing forever loop
    // int median = min + (max - min) / 2;

    // long long count = 0;
    // vector<int> v1, v2;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int value = arr[i];
    //     if (arr[i] <= median)
    //     {
    //         v1.push_back(value);
    //         count += v2.size();
    //     }
    //     else
    //         v2.push_back(value);
    // }
    
    // return count + Inversion(v1) + Inversion(v2);




    // like merge sort
    if (right - left > 0)
    {
        long long count = 0;
        int mid = (left + right) / 2;
        long long count_left = Inversion(arr, left, mid);
        // cout << arr[left] << ' ' << left;
        long long count_right = Inversion(arr, mid + 1, right);
        vector<int> v1(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> v2(arr.begin() + mid + 1, arr.begin() + right + 1);
        // cout << count_left << ' ' << count_right;
        // cout << arr[left] << ' ' << left;
        int left_index = 0, right_index = 0;
        int i = left;
        while (left_index < v1.size() && right_index < v2.size())
        {
            if (v1[left_index] > v2[right_index])
            {
                arr[i] = v2[right_index];
                count += v1.size() - left_index;
                right_index++;
            }
            else
            {
                arr[i] = v1[left_index];
                left_index++;
            }
            i++;
        }

        if (left_index == v1.size())
        {
            while (right_index != v2.size())
                arr[i++] = v2[right_index++];
        }
        else
            while (left_index != v1.size())
                arr[i++] = v1[left_index++];
        
        // cout << endl << count << endl;
        return count + count_left + count_right;
    }

    return 0;
}

int main()
{
    vector<int> arr;
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    cout << Inversion(arr, 0, N - 1) << endl;
    return 0;
}