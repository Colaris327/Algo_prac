#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class edge
{
    public:
        edge(int s, int e, int w) : start{s}, end(e), weight(w) {}
        int start;
        int end;
        int weight;
};

class vertex
{
    public:
        vertex() {}
        vertex(int n, int d) : name(n), distance(d) {}
        int name;
        int distance;
        bool finished = false;
};

class compare
{
    public:
        bool operator() (vertex x, vertex y) { return x.distance > y.distance; }
};

class Graph
{
    public:
        vector<vertex> vertices;
        priority_queue<vertex, vector<vertex> , compare> Q;
        // Edges is adjencency list
        void Dijkstra(vector<vector<edge>>& Edges, int source)
        {
            vertices.resize(Edges.size());
            for (int i = 0; i < Edges.size(); i++)
            {
                if (i == source)
                {
                    Q.push(vertex(source, 0));
                    vertices[i].distance = 0;
                }
                else
                {
                    Q.push(vertex(i, INT32_MAX));
                    vertices[i].distance = INT32_MAX;
                }
            }
            
            while (!Q.empty())
            {
                vertex current = Q.top();
                Q.pop();
                if (vertices[current.name].finished)
                    continue;

                for (auto edge_it : Edges[current.name])
                {
                    if (vertices[edge_it.end].distance == INT32_MAX || vertices[edge_it.end].distance > edge_it.weight + current.distance)
                    {
                        vertices[edge_it.end].distance = edge_it.weight + current.distance;
                        Q.push(vertex(edge_it.end, vertices[edge_it.end].distance));
                    }
                }
                vertices[current.name].finished = true;
            }
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
    G.Dijkstra(Edges, 0);
    for (auto it : G.vertices)
        cout << it.distance << ' ';

    return 0;
}