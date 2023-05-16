#include <iostream>
#include <string>
#include <vector>
#include <stack>

// std::string int_to_direction(int a)
// {
//     switch (a)
//     {
//         case 0:
//             return "\x1b[D";
//         case 1:
//             return "\x1b[A\x1b[D";
//         case 2:
//             return "\x1b[A";
//         case 3:
//             return "\x1b[D";
//         default:
//             return 0;
//     }
// }

int LCS(std::string s1, std::string s2)
{
    std::vector<std::vector<int>>  DP(s1.length() + 1, std::vector<int> (s2.length() + 1, 0));
    std::vector<std::vector<int>>  Direction(s1.length() + 1, std::vector<int> (s2.length() + 1, 0));

    for (int i = 1; i < s1.length() + 1; i++)
        for (int j = 1; j < s2.length() + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                // direction 1 is go upper left
                Direction[i][j] = 1;
            }
            else if (DP[i - 1][j] > DP[i][j - 1])
            {
                DP[i][j] = DP[i - 1][j];
                // direction 2 is go up
                Direction[i][j] = 2;
            }
            else
            {
                DP[i][j] = DP[i][j - 1];
                // direction 3 is go left
                Direction[i][j] = 3;
            }
        }

    std::cout << std::endl;
    for (int i = 0; i < s1.length() + 1; i++)
    {
        for (int j = 0; j < s2.length() + 1; j++)
            std::cout << DP[i][j] << '\t';
        std::cout << std::endl;
    }

    std::stack<int> s;
    int tmp = DP[s1.length()][s2.length()];
    int i = s1.length();
    int j = s2.length();
    while (tmp != 0)
    {
        switch (Direction[i][j])
        {
            case 0:
                j--;
                break;
            case 1:
                s.push(s1[i - 1]);
                i--;
                j--;
                break;
            case 2:
                i--;
                break;
            case 3:
                j--;
                break;
        }
        tmp = DP[i][j];
    }

    std::cout << std::endl << s1 << std::endl << s2 << std::endl << "LCS: ";
    while (!s.empty())
    {
        std::cout << char(s.top()) << ' ';
        s.pop();
    }
    std::cout << std::endl;

    return DP[s1.length()][s2.length()];
}

int main()
{
    std::string s1 = "ACGACTGGT";
    std::string s2 = "CAGTCAACT";

    int n = LCS(s1, s2);
    std::cout << "Length of LCS: " << n << std::endl;
    return 0;
}