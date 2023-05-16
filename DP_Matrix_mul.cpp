#include <iostream>
#include <vector>


// dimension is the sequence of the dimension, like A = 3x8, B = 3x1
std::vector<std::vector<int>> Matrix_Mul(std::vector<int> dimension)
{
    int length = dimension.size() - 1;
    // create a two dimension array
    std::vector<std::vector<int>> DP(length, std::vector<int> (length, 0));

    // every k means oblique direction
    for (int k = 1; k < length; k++)
    {
        for (int i = 0; i < length - k; i++)
        {
            // we are computing DP[i][j]
            int j = i + k;
            DP[i][j] = INT32_MAX;

            for (int d = i; d < j; d++)
            {
                int value = DP[i][d] + DP[d + 1][j] + dimension[i] * dimension[d + 1] * dimension[j + 1];
                if (value < DP[i][j])
                    DP[i][j] = value;
            }
        }
    }

    return DP;
}

int main()
{
    // std::vector<int> dim = {8, 3, 1, 9, 4, 3, 6, 10, 2};
    std::vector<int> dim = {2, 4, 3, 2, 5, 1};
    std::vector<std::vector<int>> ans = Matrix_Mul(dim);

    for (int i = 0; i < dim.size() - 1; i++)
    {
        for (int j = 0; j < dim.size() - 1; j++)
            std::cout << ans[i][j] << '\t';
        std::cout << std::endl;
    }
    return 0;
}