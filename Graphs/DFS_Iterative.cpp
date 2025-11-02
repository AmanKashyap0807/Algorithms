#include <iostream>
#include <vector>
#include <stack>
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

    void dfs(int v)
    {
        unordered_set<int> visited;
        stack<int> s;

        s.push(v);
        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
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
                    s.push(i);
                }
            }
        }
    }
};

int main()
{
    graph *g = new graph(5);
    g->addEdge(0, 1);
    g->addEdge(1, 0);
    g->addEdge(1, 2);
    g->addEdge(2, 1);
    g->addEdge(0, 2);
    g->addEdge(2, 0);
    g->addEdge(0, 3);
    g->addEdge(3, 0);
    g->addEdge(2, 4);
    g->addEdge(4, 2);

    g->dfs(0);
    delete g;
    return 0;
}