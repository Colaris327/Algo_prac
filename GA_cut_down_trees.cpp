// APCS h028
// https://zerojudge.tw/ShowProblem?problemid=h028
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<vector<int>> trees;
    trees.push_back({0, INT_MAX});
    int N, L, pos, height, count = 0, max = 0;
    cin >> N >> L;
    for (int i = 0; i != N; ++i)
    {
        cin >> pos;
        trees.push_back({pos});
    }
    for (int i = 1; i != N + 1; ++i)
    {
        cin >> height;
        trees[i].push_back(height);
    }
    trees.push_back({L, INT_MAX});

    stack<int> S;
    S.push(0);
    for (int i = 1; i != N + 1; ++i)
    {
        if (trees[i][0] - trees[i][1] >= trees[S.top()][0] || trees[i][0] + trees[i][1] <= trees[i + 1][0])
        {
            count++;
            if (trees[i][1] > max)
                max = trees[i][1];

            while (!S.empty())
            {
                int temp = S.top();
                if (trees[temp][0] + trees[temp][1] <= trees[i + 1][0])
                {
                    count++;
                    if (trees[temp][1] > max)
                        max = trees[temp][1];
                    S.pop();
                }
                else
                    break;
            }
        }
        else
            S.push(i);
    }
    cout << count << endl << max << endl;
}