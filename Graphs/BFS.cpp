#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
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

    void bfs(int v)
    {
        unordered_set<int> visited;
        queue<int> q;

        q.push(v);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (visited.find(curr) == visited.end())
            {
                cout << curr << " ";
                visited.insert(curr);
            }
            else
            {
                continue;
            }
            for (int i = 0; i < adjm[curr].size(); i++)
            {
                if (adjm[curr][i] == 1 && visited.find(i) == visited.end())
                {
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    graph *g = new graph(7);

    g->addEdge(0, 1);
    g->addEdge(1, 2);
    g->addEdge(0, 2);
    g->addEdge(0, 3);
    g->addEdge(1, 4);
    g->addEdge(3, 5);
    g->addEdge(5, 6);
    g->addEdge(3, 6);

    g->bfs(0);
    delete g;
    return 0;
}