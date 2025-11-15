#include <iostream>
#include <vector>
#include <climits> // <-- ADDED: Required for INT_MAX
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

    void addEdge(int u, int v, int weight)
    {
        this->adjm[u][v] = weight;
        this->adjm[v][u] = weight;
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

    int findMinVertex(vector<int> &dv, vector<bool> &known)
    {
        int minV = -1;
        int minD = INT_MAX;
        // --- FIX 1 ---
        // Loop must go to 'vertices', not 'vertices - 1'
        for (int i = 0; i < vertices; i++)
        {
            if (known[i] == false && dv[i] < minD)
            {
                minD = dv[i];
                minV = i;
            }
        }
        return minV;
    }

    void printMST(const vector<int> &pv, const vector<int> &dv)
    {
        cout << "Edge \tWeight" << endl;
        int totalWeight = 0;
        for (int i = 1; i < vertices; i++)
        {
            cout << pv[i] << " - " << i << " \t" << adjm[i][pv[i]] << endl;
            totalWeight += adjm[i][pv[i]];
        }
        cout << "Total Weight = " << totalWeight << endl;
    }

    void primsMST()
    {
        vector<int> pv(vertices, -1);
        vector<int> dv(vertices, INT_MAX);
        vector<bool> known(vertices, false);

        dv[0] = 0;
        // --- FIX 3 ---
        // Root parent should be -1, not 0
        pv[0] = -1;

        // This outer loop can be 'vertices' or 'vertices - 1', both work.
        // 'vertices - 1' is slightly more efficient.
        for (int i = 0; i < vertices - 1; i++)
        {
            int u = findMinVertex(dv, known);

            // Handle disconnected graphs (optional but good practice)
            if (u == -1)
            {
                break;
            }

            known[u] = true;

            // --- FIX 2 ---
            // Loop must go to 'vertices', not 'vertices - 1'
            for (int j = 0; j < vertices; j++)
            {
                if (adjm[u][j] != 0 && known[j] == false && adjm[u][j] < dv[j])
                {
                    dv[j] = adjm[u][j];
                    pv[j] = u;
                }
            }
        }
        printMST(pv, dv);
    }
};

int main()
{
    graph *g = new graph(7);

    // --- Inefficiency Fixed ---
    // Only need to add each edge once
    g->addEdge(0, 1, 2);
    g->addEdge(0, 2, 4);
    g->addEdge(0, 3, 1);
    g->addEdge(2, 5, 5);
    g->addEdge(2, 3, 2);
    g->addEdge(3, 5, 8);
    g->addEdge(5, 6, 1);
    g->addEdge(3, 6, 4);
    g->addEdge(3, 4, 7);
    g->addEdge(4, 6, 6);
    g->addEdge(3, 1, 3);
    g->addEdge(1, 4, 10);

    g->primsMST();

    delete g;
    return 0;
}