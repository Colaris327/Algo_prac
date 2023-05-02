// APCS 2018/02 P3
// https://zerojudge.tw/ShowProblem?problemid=f638
#include <iostream>
#include <math.h>
int sum = 0;

void Cut_ful(int *arr, int left, int right, int depth)
{
    if (right - left < 2 || depth == 0)
        return;

    // there is a O(n) solution to count the minimum fulcrum
    // calculate left torque and right torque, subtract between them, we can get torque
    int length = right - left + 1;
    int *pre_torque = new int[length];
    int *suf_torque = new int[length];
    int prefix = 0;
    int suffix = 0;

    pre_torque[0] = 0;
    for (int i = 0; i < length - 1; i++)
    {
        prefix += arr[i + left];
        pre_torque[i + 1] = pre_torque[i] + prefix;
    }

    suf_torque[length - 1] = 0;
    for (int i = length - 1; i > 0; i--)
    {
        suffix += arr[i + left];
        suf_torque[i - 1] = suf_torque[i] + suffix;
    }

    int min = INT32_MAX, min_pos;
    // i = 1 ~ length - 2, it is because that we can't let fulcrum be the left or right side.
    for (int i = 1; i < length - 1; i++)
    {
        if (std::abs(pre_torque[i] - suf_torque[i]) < min)
        {
            min_pos = i;
            min = std::abs(pre_torque[i] - suf_torque[i]);
        }
    }

    sum += arr[left + min_pos];
    delete pre_torque;
    delete suf_torque;
    Cut_ful(arr, left, left + min_pos - 1, depth - 1);
    Cut_ful(arr, left + min_pos + 1, right, depth - 1);
}

int main()
{
    int N, K;
    std::cin >> N >> K;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];

    Cut_ful(arr, 0, N - 1, K);
    std::cout << sum << std::endl;
    return 0;
}