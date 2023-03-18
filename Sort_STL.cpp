#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// from left to right, the sorted array will follow the rule of this function
bool Compare(int a, int b) {return a > b;}

int main()
{
    vector<int> data = {8, -5, -1, 4, -3, 6, 2, -2, 3, 4};

    // basic
    sort(data.begin(), data.end());
    cout << "Basic sort: \n";
    for (auto it = data.begin(); it < data.end(); it++)
        cout << setw(3) << *it << ' ';
    cout << endl;

    // sorted in ascending
    sort(data.begin(), data.end(), greater<int>());
    cout << "Sorted in ascending order: \n";
    for (auto it = data.begin(); it < data.end(); it++)
        cout << setw(3) << *it << ' ';
    cout << endl;

    // sorted using Compare function
    sort(data.begin(), data.end(), Compare);
    cout << "Sorted using Compare function: \n";
    for (auto it = data.begin(); it < data.end(); it++)
        cout << setw(3) << *it << ' ';
    cout << endl;
}