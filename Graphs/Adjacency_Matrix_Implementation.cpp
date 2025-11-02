#include <iostream>
#include <vector>
using namespace std;

class graph
{
private:
    int vertices;
    vector<vector<int>> adjm;

public:
    graph(int v)
    {
        this->vertices = v;
        this->adjm.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v)
    {
        this->adjm[u][v] = 1;
        this->adjm[v][u] = 1;
    }

    void addVer()
    {
        for (int i = 0; i < vertices; i++)
        {
            adjm[i].push_back(0);
        }
        this->vertices++;
        this->adjm.push_back(vector<int>(vertices, 0));
    }
};

int main()
{
    graph *g = new graph(5);
    g->addEdge(0, 1);
    g->addEdge(1, 0);
    g->addEdge(1, 2);
    g->addEdge(2, 1);
    g->addEdge(2, 3);
    g->addEdge(3, 2);
    g->addEdge(3, 4);
    g->addEdge(4, 3);
    return 0;
}