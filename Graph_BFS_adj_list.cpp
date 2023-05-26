#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// assume the input is adjecency list, edges[i] means vertex i's connection list
class Graph
{
    public:
        static vector<int> BFS(vector<vector<int>> edges)
        {
            int n = edges.size();
            queue<int> Q;
            // 0:white 1:gray 2:black
            vector<int> Color(n, 0);

            for (int i = 0; i < n; i++)
            {
                if (Color[i] == 0)
                {
                    Q.push(i);
                    Color[i] = 1;

                    while (!Q.empty())
                    {
                        int current = Q.front();
                        Q.pop();

                        for (auto it = edges[current].begin(); it < edges[current].end(); it++)
                            if (Color[*it] == 0)
                            {
                                Q.push(*it);
                                Color[*it] = 1;
                            }
                    }
                }
            }
            return Color;
        }
        // Count connected componet
        static int Connected_component(vector<vector<int>> edges)
        {
            int n = edges.size();
            queue<int> Q;
            // 0:white 1:gray 2:black
            vector<int> Color(n, 0);
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                if (Color[i] == 0)
                {
                    count++;
                    Q.push(i);
                    Color[i] = 1;

                    while (!Q.empty())
                    {
                        int current = Q.front();
                        Q.pop();

                        for (auto it = edges[current].begin(); it < edges[current].end(); it++)
                            if (Color[*it] == 0)
                            {
                                Q.push(*it);
                                Color[*it] = 1;
                            }
                    }
                }
            }
            return count;
        }
};

int main()
{
    vector<vector<int>> edges = {{1}, {0}, {}};

    cout << "The color after BFS: ";
    auto arr = Graph::BFS(edges);
    for (auto it = arr.begin(); it < arr.end(); it++)
        cout << *it << ' ';

    cout << endl << "Conected componets: " << Graph::Connected_component(edges) << endl;

    return 0;
}