#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class graph
{
public:
    int vertices;
    vector<vector<int>> adjm;
    vector<int> indegree;

    graph(int v)
    {
        this->vertices = v;
        this->adjm.resize(v, vector<int>(v, 0));
        this->indegree.resize(v, 0);
    }

    void adde(int u, int v)
    {
        adjm[u][v] = 1;
        indegree[v]++;
    }

    void kahnAlgo()
    {
        vector<int> TP;
        queue<int> q;

        for (int i = 0; i < vertices; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int n = q.front();
            TP.push_back(n);
            q.pop();

            for (int m = 0; m < vertices; m++)
            {
                if (adjm[n][m] == 1)
                {
                    adjm[n][m] = 0;
                    indegree[m]--;

                    if (indegree[m] == 0)
                    {
                        q.push(m);
                    }
                }
            }
        }

        bool hasEdge = false;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (adjm[i][j] == 1)
                {
                    hasEdge = true;
                    break;
                }
            }
        }

        if (hasEdge)
        {
            cout << "Graph contain cycle";
        }
        else
        {
            cout << "FOllowing is the TP";
            for (int i = 0; i < vertices; i++)
            {
                cout << TP[i] << " ";
            }
        }
    }
};

int main()
{
    graph *g = new graph(6);
    g->adde(0, 1);
    g->adde(1, 2);
    g->adde(2, 3);
    g->adde(0, 3);
    g->adde(3, 4);
    g->adde(2, 4);
    g->kahnAlgo();
    return 0;
}