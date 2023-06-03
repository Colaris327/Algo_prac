#include <iostream>
#include <vector>
using namespace std;

class edge
{
    public:
        int start;
        int end;
        int weight;
};

class Graph
{
    public:
        // min used for find min node
        // int min = INT32_MIN;
        int vertex_num;
        int total_weight = 0;
        // Distance means the distance between current spanning tree and vertex
        vector<int> Distance;
        vector<int> Predecessor;
        vector<int> Finished;
        int Find_min_vertex();
        void Prim(vector<vector<edge>>& edges);
};

int Graph::Find_min_vertex()
{
    int min = INT32_MAX;
    int index = -1;
    for (int i = 0; i < vertex_num; i++)
    {
        if (Finished[i])
            continue;
        if (Distance[i] < min)
        {
            min = Distance[i];
            index = i;
        }
    }
    return index;
}

void Graph::Prim(vector<vector<edge>>& edges)
{
    // Initialize
    vertex_num = edges.size();
    Distance.resize(vertex_num);
    Predecessor.resize(vertex_num);
    Finished.resize(vertex_num);
    for (int i = 0; i < vertex_num; i++)
    {
        Distance[i] = INT32_MAX;
        Predecessor[i] = -1;
        Finished[i] = 0;
    }

    int index = 0;
    Distance[0] = 0;
    for (int i = 0; i < vertex_num; i++)
    {
        index = Find_min_vertex();
        Finished[index] = 1;
        total_weight += Distance[index];

        for (auto it : edges[index])
        {
            // it.end is the vertex which is connected to index vertex, it.start is the index vertex
            if (!Finished[it.end] && it.weight < Distance[it.end])
            {
                Distance[it.end] = it.weight;
                Predecessor[it.end] = it.start;
            }
        }
    }
}

int main()
{
    // test with a triangle with 6, 8, 10 weight
    vector<vector<edge>> edges(3);
    edge tmp;
    tmp.start = 0;
    tmp.end = 1;
    tmp.weight = 10;
    edges[0].push_back(tmp);
    tmp.start = 1;
    tmp.end = 0;
    edges[1].push_back(tmp);
    tmp.end = 2;
    tmp.weight = 8;
    edges[1].push_back(tmp);
    tmp.start = 2;
    tmp.end = 1;
    edges[2].push_back(tmp);
    tmp.end = 0;
    tmp.weight = 6;
    edges[2].push_back(tmp);
    tmp.start = 0;
    tmp.end = 2;
    edges[0].push_back(tmp);

    Graph G;
    G.Prim(edges);
    cout << G.total_weight << endl;
    return 0;
}