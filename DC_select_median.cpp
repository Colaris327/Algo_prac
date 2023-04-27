#include <iostream>
#include <algorithm>

int Median(int data[], int length)
{
    std::sort(data, data + length);
    return data[length / 2];
}

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int Partition(int data[], int left, int right, int pivot)
{
    // let pivot change to last location
    for (int i = left; i <= right; i++)
        if (data[i] == pivot)
            Swap(data[i], data[right]);

    int i = left - 1;
    for (int j = left; j < right; j++)
        if (data[j] < pivot)
            Swap(data[++i], data[j]);

    Swap(data[right], data[++i]);
    return i;
}

int Kth_small(int data[], int left, int right, int K)
{
    int length = right - left + 1;
    int *median_arr = new int[(length + 4) / 5];
    int i;
    for (i = 0; i < length / 5; i++)
        median_arr[i] = Median(data + left + i * 5, 5);
    // the last group less than 5 members
    if (i * 5 < length)
    {
        median_arr[i] = Median(data + left + i * 5, length % 5);
        i++;
    }

    int MOM;
    if (i == 1)
        MOM = median_arr[0];
    else
        // i/2+1 is the location of median. we use recursive to make median_arr return its median
        MOM = Kth_small(median_arr, 0, i - 1, i / 2 + 1);
    delete [] median_arr;

    int pivot_index = Partition(data, left, right, MOM);
    if (pivot_index == K - 1)
        return data[pivot_index];
    else if (pivot_index > K - 1)
        return Kth_small(data, left, pivot_index - 1, K);
    else
        return Kth_small(data, pivot_index + 1, right, K);
}

int main()
{
    int arr[] = {1, 2, 4, 6, 5, 7, 11, 10, 15, 3, 4};
    std::cout << Kth_small(arr, 0, 10, 2) << std::endl;
    return 0;
}