#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Graph
{
    public:
        // for input matrix, if no edge, the slot should be -1
        vector<vector<int>> Floyd_Warshall(vector<vector<int>>& adj_matrix)
        {
            int vertex_num = adj_matrix.size();
            vector<vector<int>> result_matrix = adj_matrix;
            for (int i = 0; i < vertex_num; i++)
                for (int j = 0; j < vertex_num; j++)
                    if (result_matrix[i][j] == -1)
                        result_matrix[i][j] = INT32_MAX;

            for (int k = 0; k < vertex_num; k++)
                for (int i = 0; i < vertex_num; i++)
                    for (int j = 0; j < vertex_num; j++)
                    {
                        if (result_matrix[i][k] == INT32_MAX || result_matrix[j][k] == INT32_MAX)
                            continue;
                        if (result_matrix[i][j] > result_matrix[i][k] + result_matrix[j][k])
                            result_matrix[i][j] = result_matrix[i][k] + result_matrix[j][k];
                    }

            return result_matrix;
        }
        vector<vector<bool>> Trasitive_Closure(vector<vector<int>>& adj_matrix)
        {
            int vertex_num = adj_matrix.size();
            vector<vector<bool>> result_matrix(vertex_num, vector<bool>(vertex_num));
            for (int i = 0; i < vertex_num; i++)
                for (int j = 0; j < vertex_num; j++)
                    if (adj_matrix[i][j] >= 0)
                        result_matrix[i][j] = 1;
                    else
                        result_matrix[i][j] = 0;

            for (int k = 0; k < vertex_num; k++)
                for (int i = 0; i < vertex_num; i++)
                    for (int j = 0; j < vertex_num; j++)
                            result_matrix[i][j] = result_matrix[i][j] || (result_matrix[i][k] && result_matrix[j][k]);

            return result_matrix;
        }
};

int main()
{
    vector<vector<int>> matrix = {{0, 20, 10, 15, -1, -1, -1},
                                    {20, 0, -1, -1, 10, -1, -1},
                                    {10, -1, 0, 10, 10, 5, -1},
                                    {15, -1, 10, 0, -1, -1, 25},
                                    {-1, 10, 10, -1, 0, -1, 20},
                                    {-1, -1, 5, -1, -1, 0, 10},
                                    {-1, -1, -1, 25, 20, 10, 0}};

    Graph G;
    auto res = G.Floyd_Warshall(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
            cout << res[i][j] << '\t';
        cout << endl;
    }

    auto tr = G.Trasitive_Closure(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
            cout << tr[i][j] << '\t';
        cout << endl;
    }
    return 0;
}