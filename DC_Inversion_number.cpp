// APCS 2018/06 P4
// https://judge.tcirc.tw/ShowProblem?problemid=d064
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Inversion(vector<int> &arr)
{
    if (arr.size() <= 1)
        return 0;
    else if (arr.size() == 2)
        return arr[0] > arr[1];

    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    int median = tmp[tmp.size() / 2];

    int count = 0;
    vector<int> v1, v2;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < median)
        {
            v1.push_back(arr[i]);
            count += v2.size();
        }
        else
            v2.push_back(arr[i]);
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