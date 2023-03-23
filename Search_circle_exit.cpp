// APCS 2020/07/04
// https://zerojudge.tw/ShowProblem?problemid=f581
#include <iostream>
#include <vector>


int main()
{
    std::vector<int> arr_int;
    std::vector<int> arr_sum_prev;
    std::vector<int> mission;
    int N = 6, M = 3, temp;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        arr_int.push_back(temp);
    }
    arr_sum_prev.push_back(arr_int[0]);
    for (int i = 1; i < N; i++)
    {
        temp = arr_int[i] + arr_sum_prev[i - 1];
        arr_sum_prev.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        std::cin >> temp;
        mission.push_back(temp);
    }

    int index = 0;
    for (int i = 0; i < M; i++)
    {
        int target = (arr_sum_prev[index] - arr_int[index] + mission[i]) % *(arr_sum_prev.end() - 1);
        if (!target)
            target = arr_sum_prev[index] - arr_int[index] + mission[i];
        index = (std::lower_bound(arr_sum_prev.begin(), arr_sum_prev.end(), target) - arr_sum_prev.begin() + 1) % N;
    }

    std::cout << index % N << std::endl;
    return 0;
}