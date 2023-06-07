#include <iostream>
#include <vector>
using namespace std;

class edge
{
    public:
        edge(int s, int e, int w) : start{s}, end(e), weight(w) {}
        int start;
        int end;
        int weight;
};

class Graph
{
    public:
        vector<int> Distance;
        bool Relax(edge& e)
        {
            if (Distance[e.end] > Distance[e.start] + e.weight)
            {
                Distance[e.end] = Distance[e.start] + e.weight;
                return true;
            }
            return false;
        }
        void Initial(int source)
        {
            for (int i = 0; i < Distance.size(); i++)
                Distance[i] = INT32_MAX;
            Distance[source] = 0;
        }
        // Edges is adjencency list
        // return true means negative cycle exsist
        bool Bellman_ford(vector<vector<edge>>& Edges, int source)
        {
            Distance.resize(Edges.size());
            Initial(source);

            bool flag;
            for (int k = 1; k < Edges.size(); k++)
                for (int i = 0; i < Edges.size(); i++)
                    for (auto edge_it : Edges[i])
                        flag = Relax(edge_it);

            flag = false;
            for (int i = 0; i < Edges.size(); i++)
                for (auto edge_it : Edges[i])
                    flag = Relax(edge_it);

            return flag;
        }
};

int main()
{
    vector<vector<edge>> Edges(7);
    Edges[0].push_back(edge(0, 1, 20));
    Edges[0].push_back(edge(0, 2, 10));
    Edges[0].push_back(edge(0, 3, 15));
    Edges[1].push_back(edge(1, 4, 10));
    Edges[2].push_back(edge(2, 4, 10));
    Edges[2].push_back(edge(2, 5, 5));
    Edges[2].push_back(edge(2, 3, 10));
    Edges[3].push_back(edge(3, 6, 25));
    Edges[4].push_back(edge(4, 6, 20));
    Edges[5].push_back(edge(5, 6, 10));

    Graph G;
    cout << G.Bellman_ford(Edges, 0) << endl;
    for (auto it : G.Distance)
        cout << it << ' ';

    return 0;
}