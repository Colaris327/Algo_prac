#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> array = {8, 9, 1, 2, 3, 5, 10, 4, 2, 3, 5, 3};
    std::sort(array.begin(), array.end());
    std::cout << "sorted array: ";
    for (auto it = array.begin(); it < array.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // upper_bound 會回傳指向一串3的下一格的iterator(就跟end()一樣)
    auto upper = std::upper_bound(array.begin(), array.end(), 3);
    std::cout << "upper_bound points to : " << *upper << " (the element next to 3)" << std::endl;

    // lower_bound 會回傳指向一串3的第一格的iterator
    auto lower = std::lower_bound(array.begin(), array.end(), 3);
    std::cout << "lower_bound points to : " << *lower << " (the index of first 3)" << std::endl;

    std::cout << "the index of upper bound of 3 is " << upper - array.begin() << std::endl;
    std::cout << "the index of low bound of 3 is " << lower - array.begin() << std::endl;
}