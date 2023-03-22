// APCS 2017/03/04 P4
// https://zerojudge.tw/ShowProblem?problemid=c575
#include <iostream>
#include <vector>
#include <algorithm>

bool Check_coverable(std::vector<int>& arr, int diameter, int station_nums, int limit)
{
    int distance = 0, index = 0;
    while (station_nums && (distance < limit))
    {
        if (arr[index] > distance)
        {
            distance = arr[index] + diameter;
            station_nums--;
        }
        index++;
    }
    return distance >= limit;
}

int main()
{
    int station_nums, count, temp;
    std::vector<int> arr;
    std::cin >> count >> station_nums;
    for (int i = 0; i < count; i++)
    {
        std::cin >> temp;
        arr.push_back(temp);
    }

    std::sort(arr.begin(), arr.end());

    int left = 1, right = (*(arr.end() - 1) - *arr.begin()) / station_nums + 1, mid;
    int limit = *(arr.end() - 1);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (Check_coverable(arr, mid, station_nums, limit) &&
                !Check_coverable(arr, mid - 1, station_nums, limit))
            break;
        else if (Check_coverable(arr, mid, station_nums, limit))
            right = mid - 1;
        else
            left = mid + 1;
    }
    std::cout << mid << std::endl;
    return 0;
}