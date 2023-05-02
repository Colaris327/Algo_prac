// APCS 2018/06 P4
// https://judge.tcirc.tw/ShowProblem?problemid=d064
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long Inversion(vector<int> &arr)
{
    if (arr.size() <= 1)
        return 0;
    else if (arr.size() == 2)
        return arr[0] > arr[1];

    // don't use this, use absolute median might cause forever loop like {3, 2, 3}
    // vector<int> tmp = arr;
    // sort(tmp.begin(), tmp.end());
    // int median = tmp[tmp.size() / 2];

    int max = INT32_MIN, min = INT32_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    // all elements are same
    if (max == min)
        return 0;
    // median is an important part, must prevent from causing forever loop
    int median = min + (max - min) / 2;

    long long count = 0;
    vector<int> v1, v2;
    for (int i = 0; i < arr.size(); i++)
    {
        int value = arr[i];
        if (arr[i] <= median)
        {
            v1.push_back(value);
            count += v2.size();
        }
        else
            v2.push_back(value);
    }
    
    return count + Inversion(v1) + Inversion(v2);
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
    cout << Inversion(arr) << endl;
    return 0;
}