#include <iostream>
#include <vector>
#include <climits> // Required for INT_MAX
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

    void addDirectedEdge(int u, int v, int weight)
    {
        this->adjm[u][v] = weight;
        // Do NOT add adjm[v][u] = weight, because it's directed!
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

    int findMinDistVertex(vector<int> &dv, vector<bool> &known)
    {
        int minV = -1;
        int minD = INT_MAX;

        for (int i = 0; i < vertices; i++)
        {
            if (!known[i] && dv[i] < minD)
            {
                minD = dv[i];
                minV = i;
            }
        }
        return minV;
    }

    void printTable(const vector<int> &dv, const vector<int> &pv)
    {
        cout << "Vertex\t Known\t Dv (Dist)\t Pv (Path)" << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << "V" << i + 1 << "\t " << "true" << "\t " << dv[i] << "\t\t ";
            if (pv[i] == -1)
                cout << "0"; // Start node
            else
                cout << "V" << pv[i] + 1;
            cout << endl;
        }
    }

    void dijkstra(int startNode)
    {
        vector<int> dv(vertices, INT_MAX);
        vector<int> pv(vertices, -1);
        vector<bool> known(vertices, false);

        dv[startNode] = 0;

        for (int i = 0; i < vertices; i++)
        {
            int v = findMinDistVertex(dv, known);
            if (v == -1)
                break;
            known[v] = true;

            for (int u = 0; u < vertices; u++)
            {
                if (adjm[v][u] != 0 && !known[u])
                {
                    if (dv[v] + adjm[v][u] < dv[u])
                    {
                        dv[u] = dv[v] + adjm[v][u];
                        pv[u] = v;
                    }
                }
            }
        }
        cout << "--- Final Dijkstra Table (Matches PDF) ---" << endl;
        printTable(dv, pv);
    }
};

int main()
{
    // PDF Graph has 7 vertices (V1 to V7)
    // We use indices 0 to 6.
    graph *g = new graph(7);

    // Adding Directed Edges from PDF Page 3 Diagram
    // V1 -> V2 (2)
    g->addDirectedEdge(0, 1, 2);
    // V1 -> V4 (1)
    g->addDirectedEdge(0, 3, 1);

    // V2 -> V4 (3)
    g->addDirectedEdge(1, 3, 3);
    // V2 -> V5 (10)
    g->addDirectedEdge(1, 4, 10);

    // V3 -> V1 (4)
    g->addDirectedEdge(2, 0, 4);
    // V3 -> V6 (5)
    g->addDirectedEdge(2, 5, 5);

    // V4 -> V3 (2)
    g->addDirectedEdge(3, 2, 2);
    // V4 -> V5 (2)
    g->addDirectedEdge(3, 4, 2);
    // V4 -> V6 (8)
    g->addDirectedEdge(3, 5, 8);
    // V4 -> V7 (4)
    g->addDirectedEdge(3, 6, 4);

    // V5 -> V7 (6)
    g->addDirectedEdge(4, 6, 6);

    // V7 -> V6 (1)
    g->addDirectedEdge(6, 5, 1);

    // Run Dijkstra starting from V1 (index 0)
    g->dijkstra(0);

    delete g;
    return 0;
}