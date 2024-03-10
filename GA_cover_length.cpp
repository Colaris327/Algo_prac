// APCS b966
// https://zerojudge.tw/ShowProblem?problemid=b966
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {return a[0] < b[0];}

int main()
{
    int N, L, R;
    vector<vector<int>> lines;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> L >> R;
        lines.push_back({L, R});
    }

    sort(lines.begin(), lines.end(), cmp);
    int sum = 0, end = 0;
    for (auto line : lines)
    {
        if (line[0] >= end)
        {
            sum += line[1] - line[0];
            end = line[1];
        }
        else if (line[1] <= end)
            continue;
        else
        {
            sum += line[1] - end;
            end = line[1];
        }
    }
    cout << sum << endl;
    return 0;
}