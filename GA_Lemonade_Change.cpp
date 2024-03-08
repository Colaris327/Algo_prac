#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0, count_10 = 0, count_20 = 0;
        int length = bills.size();

        for (auto it = bills.begin(); it != bills.end(); it++)
        {
            switch (*it)
            {
            case 5:
                count_5++;
                break;

            case 10:
                if (count_5 == 0)
                    return false;
                count_5--;
                count_10++;
                break;

            case 20:
                if (count_10 != 0 && count_5 != 0)
                {
                    count_10--;
                    count_5--;
                    count_20++;
                }
                else if (count_5 >= 3)
                {
                    count_5 -= 3;
                    count_20++;
                }
                else
                    return false;
                break;

            default:
                break;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> bills = {5,5,10,10,20};
    Solution sol;
    std::cout << sol.lemonadeChange(bills);
    return 0;
}